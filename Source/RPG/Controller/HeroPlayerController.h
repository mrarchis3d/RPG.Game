// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPG/ConfigUtils/InputConfigData.h"
#include "RPG/HUD/CharacterActions.h"
#include "HeroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API AHeroPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputConfigData* InputActions;
	void Move(const FInputActionValue& Value);
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UCharacterActions> CharacterActionsWidgetClass; // Clase del UCharacterActions Widget
	UCharacterActions* CharacterActionsWidget;

public:
	void Jump();
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

};
