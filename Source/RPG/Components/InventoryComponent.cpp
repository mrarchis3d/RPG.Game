// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	InventoryItems = GetFakeItems(); 
}

void UInventoryComponent::AddItem(UItem* Item, int32 Quantity)
{
}

void UInventoryComponent::RemoveItem(UItem* Item, int32 Quantity)
{
}

TArray<UInventoryItem*> UInventoryComponent::GetInventoryItems() const
{
	return InventoryItems;
}

TArray<UInventoryItem*> UInventoryComponent::GetFakeItems() const
{
	 TArray<UInventoryItem*> fakeItems;

	UItem* Item1 = NewObject<UItem>();
	Item1->ItemName = FText::FromString(TEXT("Hammer normal"));
	FGuid::Parse("919ed59e-16aa-11ee-be56-0242ac120002", Item1->ItemID);
	Item1->ItemDescription = FText::FromString(TEXT("Tu primera Arma Aventurero"));
	Item1->MeshPath = FText::FromString(TEXT("path"));
	Item1->RarityItem = URarityItem::Normal;
	Item1->IconPath = FText::FromString(TEXT("path icon"));
	UItem* Item2 = NewObject<UItem>();
	Item2->ItemName = FText::FromString(TEXT("Hammer good"));
	FGuid::Parse("8cab74fc-c7fb-476b-becb-418feef1545f", Item2->ItemID);
	Item2->ItemDescription = FText::FromString(TEXT("Tu primera Arma Mejorada! Aventurero"));
	Item2->MeshPath = FText::FromString(TEXT("path"));
	Item2->RarityItem = URarityItem::Good;
	Item2->IconPath = FText::FromString(TEXT("path icon"));
	

	// Crea una instancia del objeto UInventoryItem
	UInventoryItem* InventoryItem1 = NewObject<UInventoryItem>();
	InventoryItem1->Item = Item1;
	InventoryItem1->Quantity = 5;
	
	UInventoryItem* InventoryItem2 = NewObject<UInventoryItem>();
	InventoryItem2->Item = Item2;
	InventoryItem2->Quantity = 2;

	
	fakeItems.Add(InventoryItem1);
	fakeItems.Add(InventoryItem2);
	return  fakeItems;
}
