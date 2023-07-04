// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RarityItem.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class URarityItem : uint8 {
	Normal = 0 UMETA(DisplayName = "Normal"),
	Uncommon = 1  UMETA(DisplayName = "Uncommon"),
	Rare = 2  UMETA(DisplayName = "Rare"),
	Good = 3  UMETA(DisplayName = "Rare"),
	Excellent = 4  UMETA(DisplayName = "Excellent"),
	Legendary = 5     UMETA(DisplayName = "Legendary"),
	Mystic = 6 UMETA(DisplayName = "Mistyc"),
	Epic = 7 UMETA(DisplayName = "Epic"),
	Ancient = 8 UMETA(DisplayName = "Ancient"),
};