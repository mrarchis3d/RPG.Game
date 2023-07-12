// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "UI/LoginWidget.h"
#include "UI/OptionsWidget.h"
#include "Components/WidgetSwitcher.h"


void UMainMenuWidget::StartPressed()
{
	if(!ensure(MenuSwitcher)) return;
	if(!ensure(LoginMenu)) return;
	LoginMenu->Open();
}

void UMainMenuWidget::OptionsPressed()
{
	if(!ensure(MenuSwitcher)) return;
	if(!ensure(OptionsMenu)) return;
	OptionsMenu->Open();
}

void UMainMenuWidget::ExitPressed()
{
	const UWorld* World = GetWorld();
	if(!ensure(World)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if(!ensure(PlayerController)) return;
	PlayerController->ConsoleCommand("quit");
}

bool UMainMenuWidget::Initialize()
{
	bool const bSuccess = Super::Initialize();
	if(!bSuccess) return false;
	if(!ensure(MenuSwitcher)) return false;
	if(!ensure(LoginMenu)) return false;
	LoginMenu->WidgetSwitcher = MenuSwitcher;
	if(!ensure(OptionsMenu)) return false;
	OptionsMenu->WidgetSwitcher = MenuSwitcher;
	if(!ensure(StartButton)) return false;
	StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::StartPressed);
	if(!ensure(OptionsButton)) return false;
	OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OptionsPressed);
	if(!ensure(ExitButton)) return false;
	ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitPressed);
	MenuSwitcher->SetActiveWidget(MainMenu);
	return true;
}
