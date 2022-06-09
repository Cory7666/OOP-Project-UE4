#include "HittableThing.hxx"

void AHittableThing::TakeDamage (AFPC &DamagedBy, const int DamageSize)
{
    EffectOnDeath (DamagedBy);
}
void AHittableThing::OnHit (Hit HitInfo)
{
    auto a = Cast<AFPC> (HitInfo.Other);
    if (a != nullptr)
        TakeDamage (*a, 10000);
}
void AHittableThing::ActorBeginOverlap (AActor &OtherActor)
{
    auto a = Cast<AFPC> (OtherActor);
    if (a != nullptr)
        TakeDamage (*a, 10000);
}
