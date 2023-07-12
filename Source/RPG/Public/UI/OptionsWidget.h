// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSubMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "Services/HttpLibrary.h"
#include "OptionsWidget.generated.h"

/**
 * Options Panel
 */
UCLASS(Abstract)
class RPG_API UOptionsWidget : public UBaseSubMenuWidget
{
	GENERATED_BODY()
private:
	virtual bool Initialize() override;
public:
	UFUNCTION()
	virtual void ExitPressed() override;
	
};
