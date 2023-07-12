// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LoginWidget.h"

#include "JsonObjectConverter.h"
#include "ConfigUtils/Utils.h"
#include "Services/HttpLibrary.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "DataModels/Login/Requests/LoginRequest.h"
#include "DataModels/Login/Responses/LoginResponse.h"

bool ULoginWidget::Initialize()
{
	const bool bIsSuccess = Super::Initialize();
	if(!ensure(ExitButton)) return false; //|| !ensure(WidgetSwitcher))  return false;
	ExitButton->OnClicked.AddDynamic(this, &ULoginWidget::ExitPressed);
	if(!ensure(LoginButton)) return false;
	LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginClicked);
	http= new HttpLibrary();
	return bIsSuccess;
}

void ULoginWidget::LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	GameInstance = Cast<UGameInstance>(this->GetGameInstance());
	if(GameInstance!=nullptr && http->ResponseIsValid(Response, bWasSuccessful))
	{
		FLoginResponse LoginResponse;
		FString JsonString = Response->GetContentAsString();
		printf("Request: %s", *Response->GetContentAsString());
		FJsonObjectConverter::JsonObjectStringToUStruct<FLoginResponse>(  JsonString, &LoginResponse, 0, 0);
		//GameInstance->Token = LoginResponse.access_token;
		printf("Response: %s", *LoginResponse.access_token);
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
		TSharedRef<IHttpRequest> Request = http->PostRequestAsFormData("http://localhost:7001/connect/token",  ContentJsonString);
		Request->OnProcessRequestComplete().BindUObject(this,  &ULoginWidget::LoginResponse);
		http->Send(Request);
	}
}

void ULoginWidget::ExitPressed()
{
	this->TearDown();
}
