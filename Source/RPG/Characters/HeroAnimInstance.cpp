// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroAnimInstance.h"

#include "HeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	HeroCharacter = Cast<AHeroCharacter>(TryGetPawnOwner());
	if(HeroCharacter)
	{
		HeroCharacterMovementComponent = HeroCharacter->GetCharacterMovement();
	}
}

void UHeroAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(HeroCharacterMovementComponent)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(HeroCharacterMovementComponent->Velocity);
		IsFalling = HeroCharacterMovementComponent->IsFalling();
	}
}
