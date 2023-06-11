// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "CharacterActions.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FJumpButtonClickedDelegate)
UCLASS()
class RPG_API UCharacterActions : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnJumpButtonClicked();

	FJumpButtonClickedDelegate JumpButtonClickedEvent;
};

