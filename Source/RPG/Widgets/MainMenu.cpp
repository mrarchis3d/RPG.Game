// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "Login.h"
#include "Components/Button.h"
#include "../ConfigUtils/Utils.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	if(StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UMainMenu::OnClickStart);
	}
}

void UMainMenu::OnClickStart()
{
	if (ULogin* LoginWidget = CreateWidget<ULogin>(GetOwningPlayer(), LoginWidgetClass))
	{
		LoginWidget->MainMenu = this;
		LoginWidget->AddToViewport();
		this->SetIsEnabled(false);
	}
}
