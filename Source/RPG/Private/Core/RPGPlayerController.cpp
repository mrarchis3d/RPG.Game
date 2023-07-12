// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "Characters/HeroCharacter.h"

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ARPGPlayerController::Move(const FInputActionValue& Value)
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

void ARPGPlayerController::Jump()
{
	this->GetCharacter()->Jump();
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// Get the local player subsystem
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(InputMapping, 0);
		if(UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(InputComponent))
		{
			PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &ARPGPlayerController::Move);
			PEI->BindAction(InputActions->JumpAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::Jump);
			PEI->BindAction(InputActions->OpenInventoryAction, ETriggerEvent::Completed, this, &ARPGPlayerController::OpenInventory);
		}
	}
}

void ARPGPlayerController::OpenInventory()
{
	// Obtén una referencia al jugador y al widget del inventario
	if (const AHeroCharacter* PlayerCharacter = Cast<AHeroCharacter>(GetCharacter()))
	{
		if (UInventoryWidget* InventoryWidget = CreateWidget<UInventoryWidget>(this, InventoryWidgetClass))
		{
			if(UInventoryComponent* InventoryComponent = PlayerCharacter->FindComponentByClass<UInventoryComponent>())
			{
				InventoryWidget->SetInventoryComponent(InventoryComponent);
				InventoryWidget->AddToViewport();
			}
		}
	}
}

