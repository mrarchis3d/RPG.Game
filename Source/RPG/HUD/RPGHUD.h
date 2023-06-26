// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RPGHUD.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGHUD : public AHUD
{
	GENERATED_BODY()
public:
	// Make BlueprintCallable for testing
	UFUNCTION( BlueprintCallable )
		void ShowMainMenu();
	UFUNCTION( BlueprintCallable )
		void HideMainMenu();
	
protected:
	UPROPERTY( EditDefaultsOnly )
	TSubclassOf<class UUserWidget> MainMenuClass;

	// Keep a pointer to be able to hide it
	UPROPERTY()
	class UUserWidget* MainMenu;
};
