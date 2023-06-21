// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RPGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API URPGGameInstance : public UGameInstance
{
	GENERATED_BODY()
    
    public:
        UPROPERTY(VisibleAnyWhere)
        FString Token;
        UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString UserName;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;
	
};
