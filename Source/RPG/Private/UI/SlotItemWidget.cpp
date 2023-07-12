// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SlotItemWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "ConfigUtils/Utils.h"

void USlotItemWidget::SetThumbnailVisibility()
{
	if(Thumbnail->Brush.GetResourceObject())
	{
		Thumbnail->SetVisibility(ESlateVisibility::Visible);
	}else
	{
		Thumbnail->SetVisibility(ESlateVisibility::Hidden);
	}
}

void USlotItemWidget::SetActiveStyle()
{
	FSlateBrush Normal;
	Normal.DrawAs = ESlateBrushDrawType::Image;
	Normal.Tiling = ESlateBrushTileType::NoTile;
	Normal.Mirroring = ESlateBrushMirrorType::NoMirror;
	Normal.TintColor = FSlateColor(FLinearColor(1.f, 0.34f, 0.015, 0.5f));

	FSlateBrush Hovered;
	Hovered.DrawAs = ESlateBrushDrawType::Image;
	Hovered.Tiling = ESlateBrushTileType::NoTile;
	Hovered.Mirroring = ESlateBrushMirrorType::NoMirror;
	Hovered.TintColor = FSlateColor(FLinearColor(1.f, 0.5f, 0, 0.5f));

	FSlateBrush Pressed;
	Pressed.DrawAs = ESlateBrushDrawType::Image;
	Pressed.Tiling = ESlateBrushTileType::NoTile;
	Pressed.Mirroring = ESlateBrushMirrorType::NoMirror;
	Pressed.TintColor = FSlateColor(FLinearColor(0.6f, 0.2f, 0.015, 0.5f));
	
	FButtonStyle DefaultStyle;
	DefaultStyle.Normal = Normal;
	DefaultStyle.Hovered = Hovered;
	DefaultStyle.Pressed = Pressed;

	if(Thumbnail->Brush.GetResourceObject())
	{
		SetThumbnailVisibility();
		SlotButton->SetStyle(DefaultStyle);
	}
}

void USlotItemWidget::SetDefaultStyle()
{
	FSlateBrush Normal;
	Normal.DrawAs = ESlateBrushDrawType::Image;
	Normal.Tiling = ESlateBrushTileType::NoTile;
	Normal.Mirroring = ESlateBrushMirrorType::NoMirror;
	Normal.TintColor = FSlateColor(FLinearColor(.4f, 0.44f, 0.44, 0.5f));

	FSlateBrush Hovered;
	Hovered.DrawAs = ESlateBrushDrawType::Image;
	Hovered.Tiling = ESlateBrushTileType::NoTile;
	Hovered.Mirroring = ESlateBrushMirrorType::NoMirror;
	Hovered.TintColor = FSlateColor(FLinearColor(1.f, 0.3f, 0.1, 0.5f));

	FSlateBrush Pressed;
	Pressed.DrawAs = ESlateBrushDrawType::Image;
	Pressed.Tiling = ESlateBrushTileType::NoTile;
	Pressed.Mirroring = ESlateBrushMirrorType::NoMirror;
	Pressed.TintColor = FSlateColor(FLinearColor(0.6f, 0.2f, 0.01, 0.5f));
	
	FButtonStyle DefaultStyle;
	DefaultStyle.Normal = Normal;
	DefaultStyle.Hovered = Hovered;
	DefaultStyle.Pressed = Pressed;

	if(Thumbnail->Brush.GetResourceObject())
	{
		SetThumbnailVisibility();
		SlotButton->SetStyle(DefaultStyle);
	}
}

bool USlotItemWidget::Initialize()
{
	const bool bSuccess =  Super::Initialize();
	if(bSuccess)
		return false;
	if(!ensure(SlotButton!=nullptr)) return false;
	if(!ensure(Thumbnail!=nullptr)) return false;
	SlotButton->OnClicked.AddDynamic(this, &USlotItemWidget::OnSlotClicked);
	SlotButton->OnHovered.AddDynamic(this, &USlotItemWidget::OnSlotHovered);
	SlotButton->OnUnhovered.AddDynamic(this, &USlotItemWidget::OnSlotUnHovered);
	return bSuccess;
}

void USlotItemWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetDefaultStyle();
	Thumbnail->SetDesiredSizeOverride(FVector2D(100.0f, 100.0f));
}

void USlotItemWidget::OnSlotClicked()
{
	SetActiveStyle();
	print("clicked");
}

void USlotItemWidget::OnSlotHovered() 
{
	if(Thumbnail->Brush.GetResourceObject())
	{
		OnHovered.Broadcast(SlotIndex);
	}
}

void USlotItemWidget::OnSlotUnHovered()
{
	OnUnHovered.Broadcast();
}
