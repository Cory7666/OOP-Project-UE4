// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "FPC.hxx"

UCLASS()
class COURSEWORK_API ABaseThing : public AActor
{
    GENERATED_BODY()
    public:
        ABaseThing (int Health, const int OnDeathPoints);
        virtual void Tick (float DeltaSeconds) = 0;

        void EffectOnDeath (AFPC &KilledBy);
        virtual void TakeDamage (AFPC &DamagedBy, const int DamageSize) = 0;
    protected:
        int Health_, OnDeathPoints_;
};
