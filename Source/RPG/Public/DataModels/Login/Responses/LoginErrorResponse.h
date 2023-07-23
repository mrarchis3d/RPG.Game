// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LoginErrorResponse.generated.h"

/**
 * Login response data
 */
USTRUCT()
struct FLoginErrorResponse
{
	GENERATED_BODY()

	UPROPERTY()  FString error;
	UPROPERTY()  FString error_description;
};
