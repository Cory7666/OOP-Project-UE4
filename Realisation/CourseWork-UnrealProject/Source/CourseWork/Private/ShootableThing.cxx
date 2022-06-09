#include "ShootableThing.hxx"

AShootableThing::AShootableThing (const int Health, const int OnHitPoints, const int OnDeathPoints)
    : Super (Health, OnHitPoints, OnDeathPoints)
{ }
void AShootableThing::TakeDamage (AFPC &DamagedBy, const int DamageSize)
{
    Health_ -= DamageSize; DamagedBy.ChangePoints (OnHitPoints_);
    if (Health_ <= 0)
    {
        EffectOnDeath (DamagedBy);
    }
}
