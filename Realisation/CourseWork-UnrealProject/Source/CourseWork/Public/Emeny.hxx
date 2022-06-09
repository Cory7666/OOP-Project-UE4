// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "ShootableThing.hxx"

UCLASS()
class COURSEWORK_API AEmeny : public AShootableThing
{
GENERATED_BODY()
public:
    AEmeny(const int Health, const int OnHitPoints, const int OnDeathPoints);
};
