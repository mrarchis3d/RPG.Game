// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataAsset.h"
#include "QuestItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UQuestItemDataAsset : public UItemDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipable Properties")
	bool bIsRemovable;

};
