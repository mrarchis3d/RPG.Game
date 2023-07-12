// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataAsset.h"
#include "Enums/RarityItem.h"
#include "AdventurerEquipableItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UAdventurerEquipableItemDataAsset : public UItemDataAsset
{
	GENERATED_BODY()
public:
	int32 MinimalDamage;

	int32 MaximalDamage;

	int32 CriticRatePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	TSoftObjectPtr<UStaticMesh> Mesh;
	
	URarityItem RarityItem;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return  FPrimaryAssetId("AdventurerEquipableItemDataAssets", GetFName());
	}
};
