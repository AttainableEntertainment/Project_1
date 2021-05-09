// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WidgetManagerHud.generated.h"

class UUserWidget;
/**
 * Class for handling all widgets display and removing
 */
UCLASS(Blueprintable)
class PROJECT__1_API AWidgetManagerHud : public AHUD
{
	GENERATED_BODY()
	
		//TODO: Add Functions 

public:
	//TODO: re factor bp into this class, try UWidget class instead
		UPROPERTY(EditAnywhere, Instanced, Category = "Widgets")
		UUserWidget* LoadingScreen;
		
		//UPROPERTY(EditAnywhere, Instanced, Category = "Widgets")
		//UUserWidget* MainMenu;

		UPROPERTY()
		UUserWidget* CurrentWidget;
		
		//UPROPERTY()
		//UUserWidget* SubWidget;
		
		//Store widgets
		//display widgets 
		//remove widgets 

		UFUNCTION()
		void ShowWidget(UUserWidget* Widget);
		
		UFUNCTION()
		void ShowLoadingScreen();
};
