// Copyright Epic Games, Inc. All Rights Reserved.


#include "Core/RPGGameModeBase.h"

#include "Blueprint/UserWidget.h"
#include "Core/RPGPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ARPGGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	DefaultPawnClass = nullptr;
	RPGPlayerController = Cast<ARPGPlayerController>( UGameplayStatics::GetPlayerController(this, 0));
	
}
