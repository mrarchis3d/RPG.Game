// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Services/HttpLibrary.h"
#include "UI/MainMenuWidget.h"
#include "UI/MenuInterface.h"
#include "RPGGameInstance.generated.h"


struct ServerData;

DECLARE_LOG_CATEGORY_EXTERN(RPGGame, Log, All);
/**
 * 
 */
UCLASS()
class RPG_API URPGGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
	
	void GetCharactersResponse(FHttpRequestPtr Request,  FHttpResponsePtr Response, bool bWasSuccessful);
	HttpLibrary* http = nullptr;
	
public:
	virtual  void Init() override;

	/////////////////
	///Menu Interface
	virtual HttpLibrary* GetHttp() 
	{
		return http;
	}
	virtual void Join(const FServerData& InServerData) override;
	virtual void StartGame() override;
	virtual void LoadMainMenu() override;
	virtual void LoadLoginMenu() override;

	/////
	///HTTP

	void SetAuthorize(FString Authorization)
	{
		if(http != nullptr)
		{
			http->SetAthorization(Authorization);
		}
	}

	FString GetAuthorize()
	{
		if(http != nullptr)
		{
			return http->GetAuthorization();
		}return "";
	}

	////////////////
	///UI Creation
	///

	UFUNCTION(BlueprintCallable, Category="RPGGameInstance|UI")
	void LoadMainMenuWidget();

	UFUNCTION(BlueprintCallable, Category="RPGGameInstance|UI")
	void LoadGameHUDWidget();

	UFUNCTION(BlueprintCallable, Category="RPGGameInstance|UI")
	void LoadInGameLoadMenuWidget();


	//////////////
	///Blueprint references, to be set in editor on defaults

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RPGGameInstance|UI")
	TSubclassOf<UMainMenuWidget> MainMenuClass;

	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RPGGameInstance|UI")
	// TSubclassOf<UMainMenu> RPGHUDClass;


	////
	///Load Characters in CharacterLevel
	
	UFUNCTION(BlueprintCallable, Category="RPGGameInstance|GetCharacters")
	void GetCharacters();

protected:
    ///DElegates funcions
    //
    void OnCreateSessionComplete(const FName SessionName, bool bSuccess);
    void OnDestroySessionComplete(const FName SessionName, bool bSuccess);
    void OnFindSessionsComplete(bool bSuccess);
    void OnJoinSessionComplete(const FName SessionName, EOnJoinSessionCompleteResult::Type Result);
    void OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);
	///Variables
	//
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
	UMainMenuWidget* MainMenu;
	
};
