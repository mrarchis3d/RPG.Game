// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/ItemTypes.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FGuid ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FText ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	TSoftObjectPtr<UTexture2D> ItemIcon;

	UItemTypes ItemType;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return  FPrimaryAssetId("ItemDataAsset", GetFName());
	}
};
