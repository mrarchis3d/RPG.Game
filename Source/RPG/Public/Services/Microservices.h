// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Microservices.generated.h"

/**
 * 
 */
USTRUCT()
struct  FMicroserviceData
{
	GENERATED_BODY()
	UPROPERTY()
	FString Name;
	UPROPERTY()
	FString Port;
public:
	FMicroserviceData() {	 }
	FMicroserviceData(FString name, FString port): Name(name), Port(port){}
};

USTRUCT()
struct FMicroservices
{
	GENERATED_BODY()
	
	FMicroserviceData* Character = new FMicroserviceData("character", "7002/");
	FMicroserviceData* Connect = new FMicroserviceData("connect", "7001/");
};



