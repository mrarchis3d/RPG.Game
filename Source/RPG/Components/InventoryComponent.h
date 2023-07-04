// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "RPG/Domain/Item.h"
#include "RPG/Domain/InventoryItem.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	public:
	UInventoryComponent();
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UItem* Item, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UItem* Item, int32 Quantity);

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<UInventoryItem*> GetInventoryItems() const;

	protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	TArray<UInventoryItem*> InventoryItems;
	
	TArray<UInventoryItem*> GetFakeItems() const;
};
