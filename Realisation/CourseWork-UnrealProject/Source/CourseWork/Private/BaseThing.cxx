#include "BaseThing.hxx"

ABaseThing::ABaseThing (int Health, const int OnDeathPoints)
    : Super(), Health_(Health), OnDeathPoints_(OnDeathPoints)
{ }

void ABaseThing::EffectOnDeath (AFPC &KilledBy)
{
    KilledBy.ChangePoints (OnDeathPoints_);
    this->DestroyActor();
}


