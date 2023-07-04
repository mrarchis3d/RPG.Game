// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPG/Structs/BaseDamage.h"
#include "RPG/Structs/BaseHealth.h"
#include "RPG/Widgets/InventoryWidget.h"
#include "HeroCharacter.generated.h"

UCLASS(config=Game)
class RPG_API AHeroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
 
private:

	
	UPROPERTY(EditAnywhere, Category="Combat Properties")
	FPhysicalDamage PhysicalDamage;

	UPROPERTY(EditAnywhere, Category="Combat Properties")
	FMagicalDamage MagicalDamage;
	
	UPROPERTY(EditAnywhere, Category="Combat Properties")
	FBaseHealth BaseHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character Base", meta=(AllowPrivateAccess = true))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character Base", meta=(AllowPrivateAccess = true))
	class UCameraComponent* FollowCamera;

};
