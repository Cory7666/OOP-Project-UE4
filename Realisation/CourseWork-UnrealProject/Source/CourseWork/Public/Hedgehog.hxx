// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "HittableThing.hxx"

UCLASS()
class COURSEWORK_API AHedgehog : public AHittableThing
{
GENERATED_BODY()
public:
    AHedgehog(const int OnDeathPoints);
};
