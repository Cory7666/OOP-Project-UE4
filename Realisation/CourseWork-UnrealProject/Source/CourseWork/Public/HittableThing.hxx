// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "BaseThing.hxx"

UCLASS()
class COURSEWORK_API AHittableThing : public ABaseThing
{
GENERATED_BODY()
public:
    AHittableThing(const int OnDeathPoints);
    virtual void OnHit (Hit HitInfo);
    virtual void ActorBeginOverlap (AActor &OtherActor);
    
    void TakeDamage (AFPC &DamagedBy, const int DamageSize);
};
