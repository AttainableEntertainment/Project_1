// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WidgetManagerHud.generated.h"

/**
 * Class for handling all widgets display and removing
 */
UCLASS()
class PROJECT__1_API AWidgetManagerHud : public AHUD
{
	GENERATED_BODY()
	
		//TODO: Add Functions 

public:
		UPROPERTY(EditAnywhere, Instanced, Category = "Widgets")
		UUserWidget* LoadingScreen;
		//Store widgets
		//display widgets 
		//remove widgets 
};
