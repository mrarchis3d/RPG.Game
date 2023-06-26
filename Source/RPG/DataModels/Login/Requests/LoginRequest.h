// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LoginRequest.generated.h"

/**
 * Login response
 */
USTRUCT()
struct FLoginRequest
{
	GENERATED_BODY()

	UPROPERTY()  FString grant_type;
	UPROPERTY()  FString client_id;
	UPROPERTY()  FString scope;
	UPROPERTY()  FString username;
	UPROPERTY()  FString password;
	UPROPERTY()  FString client_secret;
};


