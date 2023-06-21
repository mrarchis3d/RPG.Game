// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"

void AHeroPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AHeroPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MoveValue = Value.Get<FVector2D>();
	const FRotator MovementRotation(0, this->GetControlRotation().Yaw, 0);
	// Forward/Backward direction
	if (MoveValue.Y != 0.f)
	{
		// Get forward vector
		const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);

		GetCharacter()->AddMovementInput(Direction, MoveValue.Y);
	}

	// Right/Left direction
	if (MoveValue.X != 0.f)
	{
		// Get right vector
		const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
		GetCharacter()->AddMovementInput(Direction, MoveValue.X);
	}
	
}

void AHeroPlayerController::Jump()
{
	this->GetCharacter()->Jump();
}

void AHeroPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// Get the local player subsystem
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(InputMapping, 0);
		if(UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(InputComponent))
		{
			PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AHeroPlayerController::Move);
			PEI->BindAction(InputActions->JumpAction, ETriggerEvent::Triggered, this, &AHeroPlayerController::Jump);
		}
	}
}

