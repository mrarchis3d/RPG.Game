// Copyright Epic Games, Inc. All Rights Reserved.


#include "RPGGameModeBase.h"

#include "Controller/RPGPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ARPGGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	DefaultPawnClass = nullptr;
	RPGPlayerController = Cast<ARPGPlayerController>( UGameplayStatics::GetPlayerController(this, 0));

	if(RPGPlayerController)
	{
		RPGPlayerController->SetPlayerEnabledState(false);
	}
	UMainMenu* MainMenu = CreateWidget<UMainMenu>(GetWorld(), MainMenuClass);
	if (MainMenu != nullptr)
	{
		MainMenu->AddToViewport();
	}
	
}
