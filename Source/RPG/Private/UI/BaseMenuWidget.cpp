
#include "UI/BaseMenuWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"

void UBaseMenuWidget::Setup()
{
	this->AddToViewport();
	auto const World = GetWorld();
	if(!ensure(World)) return;
	const auto PlayerController = World->GetFirstPlayerController();
	if(!ensure(PlayerController)) return;
	this->SetOwningPlayer(PlayerController);

	//Set input mode data Game & UI, focus the new widget and show mouse cursor
	FInputModeGameAndUI InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputModeData);
	
	/*Center MouseLocation*/
	
	PlayerController->SetMouseLocation(
		UWidgetLayoutLibrary::GetViewportSize(this).X /2,
		UWidgetLayoutLibrary::GetViewportSize(this).Y /2
		);
	PlayerController->bShowMouseCursor = true;
}

void UBaseMenuWidget::TearDown()
{
	this->RemoveFromParent();
	const UWorld* World = GetWorld();
	if(!ensure(World)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if(!ensure(PlayerController)) return;
	const FInputModeGameAndUI InputModeData;
	PlayerController->SetInputMode(InputModeData);
}

