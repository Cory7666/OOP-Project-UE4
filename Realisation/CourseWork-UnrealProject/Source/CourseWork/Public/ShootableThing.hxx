// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "BaseThing.hxx"

UCLASS()
class COURSEWORK_API AShootableThing : public ABaseThing
{
GENERATED_BODY()
public:
    AShootableThing (const int Health, const int OnHitPoints, const int OnDeathPoints);
    virtual void TakeDamage (AFPC &DamagedBy, const int DamageSize) override;
protected:
    int OnHitPoints_;
    float Speed_,  LifeSpan_;
};
