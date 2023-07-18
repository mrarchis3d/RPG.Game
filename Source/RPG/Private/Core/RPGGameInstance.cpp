// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RPGGameInstance.h"

#include "JsonObjectConverter.h"
#include "OnlineSubsystem.h"
#include "DataModels/Character/Responses/GetCharactersByUserId.h"
#include "Engine/Engine.h"
#include "GameFramework/GameUserSettings.h"
#include "Interfaces/IHttpRequest.h"
#include "UI/MainMenuWidget.h"

DEFINE_LOG_CATEGORY(RPGGame)

void URPGGameInstance::Init()
{
	Super::Init();
	//set default screen settings
	if(GEngine)
	{
		UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
		if(UserSettings)
		{
			UserSettings->SetScreenResolution(UserSettings->GetScreenResolution());
			UserSettings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
			UserSettings->LoadSettings(false);
			UserSettings->ApplySettings(false);
		}
	}
	// Initialize http

	http= new HttpLibrary();

	// Initialize online System
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if(Subsystem)
	{
		UE_LOG(RPGGame,Log, TEXT("Found Subsytem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		if(SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &URPGGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &URPGGameInstance::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &URPGGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &URPGGameInstance::OnJoinSessionComplete);
		}
	}else
	{
		UE_LOG(RPGGame,Log, TEXT("Not Found Subsytem"));
	}
	if(GEngine)
	{
		GEngine->OnNetworkFailure().AddUObject(this, &URPGGameInstance::OnNetworkFailure);
	}
}

void URPGGameInstance::Join(const FServerData& InServerData)
{
}

void URPGGameInstance::StartGame()
{
}

void URPGGameInstance::LoadMainMenu()
{
}

void URPGGameInstance::LoadLoginMenu()
{
}

void URPGGameInstance::LoadMainMenuWidget()
{
	if(!ensure(MainMenuClass)) return;
	MainMenu = CreateWidget<UMainMenuWidget>(this, MainMenuClass);
	if(!ensure(MainMenu)) return;
	MainMenu->AddToViewport();
	MainMenu->Setup();
	
	//MainMenu->SetMenuInterface(this);
}

void URPGGameInstance::LoadGameHUDWidget()
{
}

void URPGGameInstance::LoadInGameLoadMenuWidget()
{
}

void URPGGameInstance::GetCharacters()
{
	FString ContentJsonString;
	TSharedRef<IHttpRequest> Request = http->GetRequest("http://localhost:7002/api/v1/character");
	Request->OnProcessRequestComplete().BindUObject(this,  &URPGGameInstance::GetCharactersResponse);
	http->Send(Request);
}

void URPGGameInstance::GetCharactersResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if(http->ResponseIsValid(Response, bWasSuccessful))
	{
		FGetCharactersByUserId GetCharactersResponse;
		FString JsonString = Response->GetContentAsString();
		//FJsonObjectConverter::JsonObjectStringToUStruct<FGetCharactersByUserId>(  JsonString, &GetCharactersResponse, 0, 0);
		printf("Response: %s", *JsonString);
	}else
	{
		printf("Error: %i", Response->GetResponseCode());
		print("Error: "+Response->GetContentAsString());
	}
}

void URPGGameInstance::OnCreateSessionComplete(const FName SessionName, bool bSuccess)
{
}

void URPGGameInstance::OnDestroySessionComplete(const FName SessionName, bool bSuccess)
{
}

void URPGGameInstance::OnFindSessionsComplete(bool bSuccess)
{
}

void URPGGameInstance::OnJoinSessionComplete(const FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void URPGGameInstance::OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType,
	const FString& ErrorString)
{
}
