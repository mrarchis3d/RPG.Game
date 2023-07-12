#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "BaseSubMenuWidget.generated.h"

UCLASS(Abstract)
class RPG_API UBaseSubMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UWidgetSwitcher* WidgetSwitcher;
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;
	void Open()
	{
		if(!ensure(WidgetSwitcher)) return;
		WidgetSwitcher->SetActiveWidget(this);
	}
	void TearDown()
	{
		if(!ensure(WidgetSwitcher)) return;
		WidgetSwitcher->SetActiveWidgetIndex(0);
	}
	virtual void ExitPressed() {};
};