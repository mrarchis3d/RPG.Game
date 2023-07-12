// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/RarityItem.h"
#include "ItemRarityDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UItemRarityDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	URarityItem Rarity;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture2D* TextureOverlay;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return  FPrimaryAssetId("ItemRarityDataAsset", GetFName());
	}
};
