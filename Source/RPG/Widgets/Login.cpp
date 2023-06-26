// Fill out your copyright notice in the Description page of Project Settings.


#include "Login.h"

#include "JsonObjectConverter.h"
#include "MainMenu.h"
#include "Components/EditableTextBox.h"
#include "../ConfigUtils/Utils.h"
#include "../Http/HttpLibrary.h"
#include "Components/Button.h"
#include "RPG/DataModels/Login/Requests/LoginRequest.h"
#include "RPG/DataModels/Login/Responses/LoginResponse.h"

void ULogin::NativeConstruct()
{
	Super::NativeConstruct();
	if(ExitButton)
		ExitButton->OnClicked.AddDynamic(this, &ULogin::ULogin::OnClickExit);
	if(LoginButton)
		LoginButton->OnClicked.AddDynamic(this, &ULogin::OnLoginClicked);
	http= new HttpLibrary();
	// Inicializar propiedades aquí
}

void ULogin::LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	GameInstance = Cast<URPGGameInstance>(this->GetGameInstance());
	if(GameInstance!=nullptr && http->ResponseIsValid(Response, bWasSuccessful))
	{
		FLoginResponse LoginResponse;
		FString JsonString = Response->GetContentAsString();

		printf("Holis %s", *Response->GetContentAsString());
		FJsonObjectConverter::JsonObjectStringToUStruct<FLoginResponse>(  JsonString, &LoginResponse, 0, 0);
		GameInstance->Token = LoginResponse.access_token;
		printf("Holis %s", *LoginResponse.access_token);
	}else
	{
		printf("error %s", *Response->GetContentAsString());
	}
}

void ULogin::OnLoginClicked()
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
		TSharedRef<IHttpRequest> Request = http->PostRequestAsFormData("http://localhost:7001/connect/token",  ContentJsonString);
		Request->OnProcessRequestComplete().BindUObject(this,  &ULogin::LoginResponse);
		http->Send(Request);
		print("envio??")
	}
}

void ULogin::OnClickExit()
{
	if( MainMenu)
	{
		MainMenu->SetIsEnabled(true);
		this->RemoveFromParent();
	}
}
