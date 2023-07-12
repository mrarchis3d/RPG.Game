// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemTypes.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class UItemTypes: uint8 {
	Quest = 0 UMETA(DisplayName = "Quest Item"),
	Adventurer = 1 UMETA(DisplayName = "Adventurer Item"),
};