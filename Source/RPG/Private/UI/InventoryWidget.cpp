// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWidget.h"
#include "UI/SlotItemWidget.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UInventoryWidget::OnClickExit);
	}
}


void UInventoryWidget::OnClickExit()
{
	this->RemoveFromParent();
}

void UInventoryWidget::SetSlotInfo(int32 Index, int32 RowCount, int32 ColumnCount, UInventoryItem* Item)
{
	//USlotItemWidget* NewSlot = CreateNewSlot(Index, RowCount, ColumnCount);
	if(Item!=nullptr)
	{
		
	}
		
}

void UInventoryWidget::BuildSlots(TArray<UInventoryItem*> InventoryItems)
{
	SlotsGrid->ClearChildren();
	if(AmountOfSlotsTotal >0)
	{
		int32 RowCount = 0;
		int32 ColumnCount =0;
		for(int32 i = 0; i<AmountOfSlotsTotal;i++)
		{
			if (InventoryItems.IsValidIndex(i))
				SetSlotInfo(i, RowCount, ColumnCount, InventoryItems[i]);
			else
				SetSlotInfo(i, RowCount, ColumnCount);
		}
	}
	//NoItemsBorder->SetVisibility(ESlateVisibility::Visible);
}

void UInventoryWidget::GetInventoryItems()
{
	if (InventoryComponent)
	{
		TArray<UInventoryItem*> items = InventoryComponent->GetInventoryItems();
		BuildSlots(items);
		AmountOfSlotsTotal = InventoryComponent->GetInventorySlots();
		AmountOfSlots = items.Num();
	}
}
