// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/IHttpRequest.h"
#include "RPG/RPGGameInstance.h"
#include "UObject/Object.h"
#include "Login.generated.h"

class HttpLibrary;
/**
 * 
 */
UCLASS()
class RPG_API ULogin : public UUserWidget
{
	GENERATED_BODY()

private:
	URPGGameInstance* GameInstance;
	HttpLibrary* http;
	virtual void NativeConstruct() override;
	void LoginResponse(FHttpRequestPtr Request,  FHttpResponsePtr Response, bool bWasSuccessful);

public:
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* UsernameField;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* PasswordField;

	UFUNCTION()
	void OnLoginClicked();
	
};
