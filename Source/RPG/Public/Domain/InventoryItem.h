// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/ItemDataAsset.h"
#include "UObject/Object.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryItem")
	UItemDataAsset* Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryItem")
	int32 Quantity;

	// Otros atributos y funciones según tus necesidades
};