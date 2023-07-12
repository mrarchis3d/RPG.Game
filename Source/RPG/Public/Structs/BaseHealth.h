#pragma once

#include "BaseHealth.generated.h"

USTRUCT()
struct RPG_API FBaseHealth
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float PhysicalArmor;
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float MagicalArmor;
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float MaxHealth;
	UPROPERTY(EditDefaultsOnly, Category = "Combat Properties")
	float LifeRegeneration;
};