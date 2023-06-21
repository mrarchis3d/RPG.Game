// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LoginResponse.generated.h"

/**
 * Login response data
 */
USTRUCT()
struct FLoginResponse
{
	GENERATED_BODY()

	UPROPERTY()  FString access_token;
	UPROPERTY()  FString token_type;
	UPROPERTY()  FString scope;
	UPROPERTY()  int32 expires_in;
};
