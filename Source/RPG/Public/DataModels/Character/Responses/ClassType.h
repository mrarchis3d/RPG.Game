#pragma once

#include "CoreMinimal.h"
#include "ClassType.generated.h"

/**
 * ClassType //GET
 */
USTRUCT()
struct FClassType
{
	GENERATED_BODY()

	UPROPERTY()  FGuid Id;
	UPROPERTY()  FString Name;
	UPROPERTY()  FString Description;
};
