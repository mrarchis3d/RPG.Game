// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlotItemWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotHovered, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSlotUnHovered);

/**
 * 
 */
UCLASS()
class RPG_API USlotItemWidget : public UUserWidget
{
	GENERATED_BODY()

public :
	UPROPERTY(BlueprintReadWrite, Category="Slot Properties")
	int32 SlotIndex;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* SlotButton;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* Thumbnail;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UBorder* AmountBorder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* AmountText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* RarityTexture;

	UPROPERTY(BlueprintAssignable, Category="EventDispatchers")
	FOnSlotHovered OnHovered;

	UPROPERTY(BlueprintAssignable, Category="EventDispatchers")
	FOnSlotUnHovered OnUnHovered;

	UFUNCTION()
	void SetThumbnailVisibility();
	UFUNCTION()
	void SetActiveStyle();
	UFUNCTION()
	void SetDefaultStyle();

protected:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;
	// virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	// virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;

	//Button Events
	UFUNCTION()
	void OnSlotClicked();
	UFUNCTION()
	void OnSlotHovered();
	UFUNCTION()
	void OnSlotUnHovered();

	
	
};
