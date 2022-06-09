#include "FPC.hxx"

AFPC::AFPC (const float PlayTime)
    : Super(), PlayTime_(PlayTime), Score_(0), TotalShoots_(0), TotalHits_(0), KillsHittableItems_(0)
{
    IsPolygon_ = true;
}

void AFPC::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override
{
    PlayerInputComponent->BindAxis (this, "Turn", &(Super::ControllerYawInput));
    PlayerInputComponent->BindAxis (this, "LookUp", &(Super::ControllerPitchInput));
    PlayerInputComponent->BindAxis (this, "MoveForward", &(Super::MovementInput));
    PlayerInputComponent->BindAxis (this, "MoveRight", &(Super::MovementInput));
    PlayerInputComponent->BindAction (this, "Jump", PRESSED, &(Super::Jump));
    PlayerInputComponent->BindAction (this, "Jump", RELEASED, &(Super::Jump));
    PlayerInputComponent->BindKey (this, "Escape", PRESSED, &(AFPS::OpenMainMenu));
}

void AFPC::Shoot ()
{
    auto  CameraLocation = GetComponent(NAME("FirstPersonCamera"))->GetWorldLocation(),
          CameraForwardVector = GetComponent(NAME("FirstPersonCamera"))->GetForwardVector();
    auto Result = LineTraceByChannel (CameraLocation, CameraForwardVector * 50000 + CameraLocation);
    auto TracedActor = Cast<ABaseThing> (Result.HitActor);
    if (TracedActor != nullptr)
    {
        TracedActor->TakeDamage (*this, 40.0);
        TotalHits_ += 1;
    }
    TotalShoots_ += 1;
}

void AFPC::OpenMainMenu()
{
    GetWorld()->OpenLevel (NAME("LevelMainMenu"));
}

void AFPC::ChangePoints (value points)
{
    Score_ += value;
}

void AFPC::Tick (float DeltaSeconds)
{
    PassedTime_ += DeltaSeconds;
    if (PassedTime_ >= PlayTime_)
    {
        if (!IsPolygon_)
        {
            GetWorld()→SetGamePaused(true);
            OpenMainMenu();
        }
    }
}
