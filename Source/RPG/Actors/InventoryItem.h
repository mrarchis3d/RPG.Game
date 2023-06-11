// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "RPG/Components/InventoryComponent.h"
#include "Item.generated.h"


class USphereComponent;

UCLASS()
class RPG_API AInventoryItem : public AItem
{
	GENERATED_BODY()
	
public:	
	virtual void Tick(float DeltaTime) override;

	
protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	unsigned int Quantity = 0;
	
	GUID Id;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
};

