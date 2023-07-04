// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPG/Enums/RarityItem.h"
#include "UObject/Object.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class RPG_API UItem : public UObject
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
	FText MeshPath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FText IconPath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	URarityItem RarityItem;

private:
	UTexture2D* RarityTexture;
 
	// Otros atributos y funciones según tus necesidades
};