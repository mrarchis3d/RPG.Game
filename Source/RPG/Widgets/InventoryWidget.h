// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Blueprint/UserWidget.h"
#include "Components/Overlay.h"
#include "RPG/Components/InventoryComponent.h"
#include "RPG/Domain/InventoryItem.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	virtual void NativeConstruct() override;

public:
	// Función de configuración para establecer el InventoryComponent
	void SetInventoryComponent(UInventoryComponent* InInventoryComponent)
	{
		InventoryComponent = InInventoryComponent;
	}
	UFUNCTION()
	void OnClickExit();
protected:
	UPROPERTY()
	UOverlay* InventoryOverlay;
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TArray<UInventoryItem*> InventoryItems;
	
	UInventoryComponent* InventoryComponent;
};