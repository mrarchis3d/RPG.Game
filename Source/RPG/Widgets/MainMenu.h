// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Login.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class RPG_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Widget To Load")
	TSubclassOf<ULogin> LoginWidgetClass;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* StartButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* OptionsButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* ExitButton;

	UFUNCTION()
	void OnClickStart();
	
};
