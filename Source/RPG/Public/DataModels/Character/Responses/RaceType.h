#pragma once

#include "CoreMinimal.h"
#include "RaceType.generated.h"

/**
* RaceType //GET
 */
USTRUCT()
struct FRaceType
{
	GENERATED_BODY()

	UPROPERTY()  FGuid Id;
	UPROPERTY()  FString Name;
	UPROPERTY()  FString Description;
};