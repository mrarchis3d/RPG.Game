// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/InventoryComponent.h"
#include "Domain/InventoryItem.h"
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

	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* SlotsGrid;
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;
private:
	void SetSlotInfo(int32 INT32, int32 RowCount, int32 ColumnCount, UInventoryItem* Element = nullptr);
	void BuildSlots(TArray<UInventoryItem*> InventoryItems);

	void GetInventoryItems();
	int32 AmountOfSlotsTotal;
	int32 AmountOfSlots;
	
	UInventoryComponent* InventoryComponent;
};