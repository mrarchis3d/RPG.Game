// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGHUD.h"

#include "Blueprint/UserWidget.h"
#include "RPG/Controller/RPGPlayerController.h"
#include "RPG/Widgets/MainMenu.h"

void ARPGHUD::ShowMainMenu()
{
	// Make widget owned by our PlayerController
	APlayerController* PC = Cast<ARPGPlayerController>( GetOwner() );
	MainMenu = CreateWidget<UMainMenu>( PC, MainMenuClass );
	MainMenu->AddToViewport();
}

void ARPGHUD::HideMainMenu()
{
	if ( MainMenu )
	{
		MainMenu->RemoveFromParent();
		MainMenu = nullptr;
	}
}