// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSubMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "Core/RPGGameInstance.h"
#include "Interfaces/IHttpRequest.h"
#include "Services/HttpLibrary.h"
#include "LoginWidget.generated.h"


/**
 * Login panel
 */
UCLASS(Abstract)
class RPG_API ULoginWidget : public UBaseSubMenuWidget
{
	GENERATED_BODY()
private:
	UPROPERTY()
	URPGGameInstance* GameInstance;
	virtual bool Initialize() override;
	void LoginResponse(FHttpRequestPtr Request,  FHttpResponsePtr Response, bool bWasSuccessful);

public:
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* UsernameField;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* PasswordField;

	UPROPERTY(meta = (BindWidget))
	class UButton* LoginButton;

	UFUNCTION()
	void OnLoginClicked();

	UFUNCTION()
	virtual void ExitPressed() override;
	
};
