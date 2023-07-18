// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LoginWidget.h"

#include "JsonObjectConverter.h"
#include "ConfigUtils/Utils.h"
#include "Services/HttpLibrary.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Core/RPGGameInstance.h"
#include "DataModels/Login/Requests/LoginRequest.h"
#include "DataModels/Login/Responses/LoginResponse.h"

bool ULoginWidget::Initialize()
{
	const bool bIsSuccess = Super::Initialize();
	if(!ensure(ExitButton)) return false; //|| !ensure(WidgetSwitcher))  return false;
	ExitButton->OnClicked.AddDynamic(this, &ULoginWidget::ExitPressed);
	if(!ensure(LoginButton)) return false;
	LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginClicked);
	GameInstance = Cast<URPGGameInstance>(this->GetGameInstance());
	if(!ensure(GameInstance)) return false;
	return bIsSuccess;
}

void ULoginWidget::LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if(GameInstance->GetHttp()->ResponseIsValid(Response, bWasSuccessful))
	{
		FLoginResponse LoginResponse;
		FString JsonString = Response->GetContentAsString();
		FJsonObjectConverter::JsonObjectStringToUStruct<FLoginResponse>(  JsonString, &LoginResponse, 0, 0);
		GameInstance->SetAuthorize(LoginResponse.access_token);
		printf("Token: %s", *GameInstance->GetAuthorize());

		GameInstance->GetCharacters();
		print("GetCharacters");
	}else
	{
		printf("Error: %i", Response->GetResponseCode());
		print("Error: "+Response->GetContentAsString());
	}
}

void ULoginWidget::OnLoginClicked()
{
	if(UsernameField!=nullptr &&
		PasswordField != nullptr &&
		!UsernameField->GetText().ToString().IsEmpty() &&
		!PasswordField->GetText().ToString().IsEmpty())
	{
		FLoginRequest LoginCredentials;
		LoginCredentials.client_id = "unrealdesktop";
		LoginCredentials.grant_type = "password";
		LoginCredentials.username = UsernameField->GetText().ToString();
		LoginCredentials.password = PasswordField->GetText().ToString();
		LoginCredentials.client_secret = "SuperSecretPassword";
		FString ContentJsonString;
		FJsonObjectConverter::UStructToJsonObjectString(FLoginRequest::  StaticStruct(), &LoginCredentials, ContentJsonString, 0, 0);
		TSharedRef<IHttpRequest> Request = GameInstance->GetHttp()->PostRequestAsFormData("http://localhost:7001/connect/token",  ContentJsonString);
		Request->OnProcessRequestComplete().BindUObject(this,  &ULoginWidget::LoginResponse);
		GameInstance->GetHttp()->Send(Request);
	}
}

void ULoginWidget::ExitPressed()
{
	this->TearDown();
}
