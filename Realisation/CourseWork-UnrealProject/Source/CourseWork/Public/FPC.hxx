// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"
#include "BaseThing.hxx"

UCLASS()
class COURSEWORK_API AFPC : public AFirstPersonCharacter
{
GENERATED_BODY()
public:
        AFPC(const float PlayTime);
        void Shoot();
        void OpenMainMenu();
	    void ChangePoints(int value);
        virtual void Tick (float DeltaSeconds) override;
        virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    int KillsHittableItems_,
        TotalShoots_,
        TotalHits_,
        Score_;
    float PassedTime_, PlayTime_;
    bool IsPolygon_;
};
