// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBase_2D.generated.h"

class ULevelManager;
class UGameSaveManager;
class AWidgetManagerHud;

/**
 * Game mode base class for 2d platform game
 */
UCLASS(Blueprintable)
class PROJECT__1_API AGameModeBase_2D : public AGameModeBase
{
	GENERATED_BODY()
	

private:
	UPROPERTY()
	ULevelManager* LevelManager;

	UPROPERTY()
	UGameSaveManager* SaveManager;

public:
	AGameModeBase_2D();

	UPROPERTY()
	AWidgetManagerHud* WidgetManager;

protected:
	virtual void BeginPlay() override;

	void Initialise();

	void OpenLevelFor2DGame(FName LevelName);
	
};
