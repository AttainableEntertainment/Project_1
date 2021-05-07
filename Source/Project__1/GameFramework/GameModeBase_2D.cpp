// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase_2D.h"
#include "Kismet/GameplayStatics.h"
#include "LevelManager.h"

AGameModeBase_2D::AGameModeBase_2D()
{
	UE_LOG(LogTemp, Warning, TEXT("Game mode constructor"));
}

void AGameModeBase_2D::BeginPlay()
{
	Super::BeginPlay();

	
	if (!GetGameInstance()->GetSubsystem<ULevelManager>())
	{
		UE_LOG(LogTemp, Error, TEXT("Game mode cant find LevelManager"));
		return;
	}
	LevelManager = GetGameInstance()->GetSubsystem<ULevelManager>();
	
	//testing 
	OpenLevelFor2DGame("L_LevelSelect");
}
void AGameModeBase_2D::OpenLevelFor2DGame(FName LevelName)
{
	LevelManager->OpenLevelFromManager(LevelName);
}

//handles UI 
//
