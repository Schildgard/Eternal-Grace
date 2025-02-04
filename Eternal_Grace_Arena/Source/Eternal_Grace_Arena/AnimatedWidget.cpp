// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimatedWidget.h"

void UAnimatedWidget::NativeConstruct()
{
	Super::NativeConstruct();
	EndDelegate.BindDynamic(this, &UAnimatedWidget::BlendOut);
	BindToAnimationFinished(BlendOutAnimation, EndDelegate);
}

void UAnimatedWidget::BlendOut()
{
	RemoveFromViewport();
}

UWidgetAnimation* UAnimatedWidget::GetBlendInAnimation()
{
	return BlendingAnimation;
}

UWidgetAnimation* UAnimatedWidget::GetBlendOutAnimation()
{
	return BlendOutAnimation;
}
