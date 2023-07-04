// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "Components/Button.h"
#include "RPG/ConfigUtils/Utils.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (InventoryComponent)
	{
		InventoryItems = InventoryComponent->GetInventoryItems();
		for (const UInventoryItem* item : InventoryItems)
		{
			printf("item: %s", *item->Item->ItemName.ToString());
		}
	}
	if(ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UInventoryWidget::OnClickExit);
	}
}


void UInventoryWidget::OnClickExit()
{
	this->RemoveFromParent();
}