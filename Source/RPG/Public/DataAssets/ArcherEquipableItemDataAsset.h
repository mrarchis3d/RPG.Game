// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataAsset.h"
#include "Enums/RarityItem.h"
#include "ArcherEquipableItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UArcherEquipableItemDataAsset : public UItemDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	int32 MinimalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	int32 MaximalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	int32 CriticRatePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	USkeletalMesh* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	URarityItem RarityItem;
};
