// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"

void UDialogueWidget::UpdateDialogueText(FText InputText)
{

	DisplayText->SetText(InputText);
}

FText UDialogueWidget::GetDisplayText()
{
	return DisplayText->GetText();
}
