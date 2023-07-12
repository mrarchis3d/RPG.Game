// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UHeroAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	UPROPERTY(BlueprintReadOnly)
	class AHeroCharacter* HeroCharacter;
	UPROPERTY(BlueprintReadOnly, Category=Movement)
	class UCharacterMovementComponent* HeroCharacterMovementComponent;
	UPROPERTY(BlueprintReadOnly, Category=Movement)
	float GroundSpeed;
	UPROPERTY(BlueprintReadOnly, Category=Movement)
	bool IsFalling;
};
