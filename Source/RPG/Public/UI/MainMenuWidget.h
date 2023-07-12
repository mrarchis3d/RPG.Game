// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMenuWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * MainMenu Widget
 */
UCLASS(Abstract)
class RPG_API UMainMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

private:

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class UButton* StartButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class UButton* OptionsButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class UButton* ExitButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class UWidget* MainMenu;
	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class UOptionsWidget* OptionsMenu;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class ULoginWidget* LoginMenu;
	
	UFUNCTION()
	void StartPressed();

	UFUNCTION()
	void OptionsPressed();

	UFUNCTION()
	void ExitPressed();

	virtual bool Initialize() override;
	
};
