#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.generated.h"


class IRPGMenuInterface;

UCLASS(Abstract)
class RPG_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess= true))
	class UWidgetSwitcher* MenuSwitcher;

public:
	void Setup();
	void TearDown();
	
};