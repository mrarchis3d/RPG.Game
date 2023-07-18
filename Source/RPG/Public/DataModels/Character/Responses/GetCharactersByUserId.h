// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClassType.h"
#include "RaceType.h"
#include "GetCharactersByUserId.generated.h"


/*
  {
  	"id": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
	  "userId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
	  "nickName": "string",
	  "description": "string",
	  "level": 0,
	  "experience": 0,
	  "professionLevel": 0,
	  "professionExperience": 0,
	  "classTypeId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
	  "raceTypeId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
	  "user": {
	  	"userName": "string",
		  "fullName": "string",
		  "userId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
		  "character": "string"
		},
		"classType": {
			"id": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
			"name": "string",
			"character": "string"
		  },
		  "raceType": {
		  	"id": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
			  "name": "string",
			  "description": "string",
			  "character": "string"
			}
  }
]
*/

/**
 * Get Character By User Response //GET
 */
USTRUCT()
struct FGetCharactersByUserId
{
	GENERATED_BODY()

	UPROPERTY()  FGuid Id;
	UPROPERTY()  FString NickName;
	UPROPERTY()  FString Description;
	UPROPERTY()  int32 Level;
	UPROPERTY()  int64 Experience;
	UPROPERTY()  int32 ProfessionLevel;
	UPROPERTY()  int64 ProfessionExperience;
	UPROPERTY()  FClassType ClassType;
	UPROPERTY()  FRaceType RaceType;
};


