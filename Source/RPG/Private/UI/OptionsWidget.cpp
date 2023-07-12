// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OptionsWidget.h"
#include "JsonObjectConverter.h"
#include "Services/HttpLibrary.h"
#include "Components/Button.h"

bool UOptionsWidget::Initialize()
{
	const bool bIsSuccess = Super::Initialize();
	if(!ensure(ExitButton)) return false; //|| !ensure(WidgetSwitcher))  return false;
	ExitButton->OnClicked.AddDynamic(this, &UOptionsWidget::ExitPressed);
	return bIsSuccess;
}

void UOptionsWidget::ExitPressed()
{
	this->TearDown();
}
