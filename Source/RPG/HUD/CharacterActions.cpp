// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterActions.h"

void UCharacterActions::OnJumpButtonClicked()
{
	JumpButtonClickedEvent.ExecuteIfBound();
}

