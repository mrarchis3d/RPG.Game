// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/AdventurerEquipableItemDataAsset.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	InventoryItems = GetFakeItems(); 
}

void UInventoryComponent::AddItem(UItemDataAsset* Item, int32 Quantity)
{
}

void UInventoryComponent::RemoveItem(UItemDataAsset* Item, int32 Quantity)
{
}

TArray<UInventoryItem*> UInventoryComponent::GetInventoryItems() const
{
	return InventoryItems;
}

TArray<UInventoryItem*> UInventoryComponent::GetFakeItems() const
{
	 TArray<UInventoryItem*> fakeItems;
	
	UAdventurerEquipableItemDataAsset* Item1 = NewObject<UAdventurerEquipableItemDataAsset>();
	Item1->RarityItem = URarityItem::Normal;
	UAdventurerEquipableItemDataAsset* Item2 = NewObject<UAdventurerEquipableItemDataAsset>();
	Item2->RarityItem = URarityItem::Good;
	
	
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
