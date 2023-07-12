// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"


// Define a struct to store the loaded data assets
struct FLoadedDataAsset
{
	FString AssetID;
	UDataAsset* LoadedAsset;
};

// Function to asynchronously load a data asset by its ID
void LoadDataAssetByID(const FString& AssetID, TArray<FLoadedDataAsset>& LoadedDataAssets)
{

	// Generate the asset path or reference based on the provided AssetID// Replace this with your own logic to generate the asset path

	if(UAssetManager* AssetManager = UAssetManager::GetIfValid())
	{
		FPrimaryAssetId AssetId = FPrimaryAssetId(AssetID);
		FAssetData AssetToParse;
		AssetManager->GetPrimaryAssetData(AssetId, AssetToParse);

	}
}