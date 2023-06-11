// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons.h"
#include "../Constants/Consts.h"
#include "../Characters/HeroCharacter.h"

void AWeapons::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if(AHeroCharacter* HeroCharacter  = Cast<AHeroCharacter>(OtherActor))
	{
		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
		ItemMesh->AttachToComponent(HeroCharacter->GetMesh(), TransformRules, CharacterHandRightSocket);
		Amplitude = 0.0f;
	}
}

void AWeapons::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}
