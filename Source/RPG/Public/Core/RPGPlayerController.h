// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DataAssets/InputConfigData.h"
#include "UI/InventoryWidget.h"
#include "RPGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputConfigData* InputActions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Widget To Load")
	TSubclassOf<UInventoryWidget> InventoryWidgetClass;

	
	void Move(const FInputActionValue& Value);

public:

	UFUNCTION(BlueprintCallable)
	void Jump();
	void OpenInventory();

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

};
