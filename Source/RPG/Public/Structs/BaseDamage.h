// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDamage.generated.h"

USTRUCT()
struct RPG_API FMagicalDamage
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float Damage = 0;
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float ArmorPenetration = 0;
	//Percentage acts as multiplier
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float CriticalStrike = 1.0f;
};

USTRUCT()
struct RPG_API FPhysicalDamage
{
	GENERATED_BODY()
	FPhysicalDamage(float Damage, float CriticalProbability): Damage(Damage), CriticalProbability(CriticalProbability) {}
	FPhysicalDamage() {	 }
public:
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float Damage = 0;
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float ArmorPenetration = 0;
	//Percentage
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float CriticalProbability = 0;
	//Percentage acts as multiplier
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float CriticalStrike = 20.f;
	//Percentage
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float LifeSteal = 0;
};

