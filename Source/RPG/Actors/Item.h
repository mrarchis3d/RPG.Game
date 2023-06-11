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
class RPG_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;
	bool bIsMesh = ItemMesh != nullptr;
	GUID GetId() {
		return Id;
	};

	unsigned int GetQuantity()
	{
		return Quantity;
	};
	
	void PlusQuantity(unsigned int Value)
	{
		Quantity += Value;
	};

	void MinusQuantity(unsigned int Value)
	{
		Quantity -= Value;
	};
	void SetQuantity(unsigned int Value)
	{
		Quantity = Value;
	};
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Parameters")
	FName Name = "";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;
	
	UPROPERTY(EditAnywhere, Category = "FX")
	UNiagaraSystem* VisibleFX;


private:
	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();
	
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	unsigned int Quantity = 0;
	
	GUID Id;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
	template<typename T>
	T Avg(T First, T Second);

};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}