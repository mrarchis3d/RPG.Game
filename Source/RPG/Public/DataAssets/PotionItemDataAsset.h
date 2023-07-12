// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataAsset.h"
#include "PotionItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UPotionItemDataAsset : public UItemDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 RestoreHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 RestoreMana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 RestorePercentageHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 RestorePercentageMana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 Seconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	bool bIsSpecial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 IncreaseExperience;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 IncreaseProfession;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 IncreaseExperienceByPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 IncreaseProfessionByPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 IncreaseAttackByPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable Properties")
	int32 IncreaseDefenseByPercentage;
};
