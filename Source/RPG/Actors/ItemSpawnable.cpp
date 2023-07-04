// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSpawnable.h"
#include "RPG/ConfigUtils/Utils.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Materials/MaterialInstanceDynamic.h"


AItemSpawnable::AItemSpawnable()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
	//
	// static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/Assets/SM_PlaneIcon.uasset"));
	// if (StaticMeshAsset.Succeeded())
	// {
	// 	ItemMesh->SetStaticMesh(StaticMeshAsset.Object);
	// }
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItemSpawnable::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItemSpawnable::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItemSpawnable::OnOverlapEnd);
	if (Effect) {
		// This spawns the chosen effect on the owning WeaponMuzzle SceneComponent
		if( UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(Effect, RootComponent, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::Type::KeepRelativeOffset, true))
			NiagaraComp->SetNiagaraVariableLinearColor(FString("Color01"), FLinearColor(0.900000,0.900000,0.900000,0.010000));
	}

	IconMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("/Game/Materials/Items/M_SpawnableItem")));
	if (IconMaterial)
	{
		UMaterialInstanceDynamic* MaterialInstance = UMaterialInstanceDynamic::Create(IconMaterial, nullptr);
		if (MaterialInstance)
		{
			// Suponiendo que tienes una variable llamada "IconTextureParameterName" que representa el nombre del parámetro "IconTexture"
			//deberia ser con el path que venga de la base de datos
			FString basePath = FString("/Game/Textures/Items/TX_") + FString("919ed59e-16aa-11ee-be56-0242ac120002");

			UTexture* IconTexture = LoadObject<UTexture>(nullptr, *basePath);
			if (IconTexture)
			{
				MaterialInstance->SetTextureParameterValue(FName("IconTexture"), IconTexture);
			}
		}
	}


}

float AItemSpawnable::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}
float AItemSpawnable::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItemSpawnable::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	printf_c(FColor::Blue, "Overlaped: %s",*OtherActorName);
}

void AItemSpawnable::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = OtherActor->GetName();
	printf("End Overlap: %s",*OtherActorName);
}

// Called every frame
void AItemSpawnable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
}
