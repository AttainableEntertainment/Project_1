// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget2D_Base.generated.h"



/**
 * 
 */
UCLASS()
class PROJECT__1_API UUserWidget2D_Base : public UUserWidget
{
	GENERATED_BODY()
public:
	UUserWidget2D_Base(const FObjectInitializer& ObjectInitializer);
	virtual bool Initialize() override;

	// Optionally override the Blueprint "Event Construct" event
	virtual void NativeConstruct() override;

	// Optionally override the tick event
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:

	TArray<class UButton*> Buttons;
	
	//class FTimerHandle TimeHandle;
	
};
