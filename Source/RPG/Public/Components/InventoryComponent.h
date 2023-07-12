// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DataAssets/ItemDataAsset.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "Domain/InventoryItem.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	int32 InventorySlots = 16;

public:
	UInventoryComponent();
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UItemDataAsset* Item, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UItemDataAsset* Item, int32 Quantity);

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<UInventoryItem*> GetInventoryItems() const;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	int32 const GetInventorySlots() {  return InventorySlots;  }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	TArray<UInventoryItem*> InventoryItems;
	
	TArray<UInventoryItem*> GetFakeItems() const;
};
