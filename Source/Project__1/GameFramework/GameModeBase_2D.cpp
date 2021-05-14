// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase_2D.h"

#include "GameSaveManager.h"
#include "Kismet/GameplayStatics.h"
#include "LevelManager.h"
#include "WidgetManagerHud.h"

AGameModeBase_2D::AGameModeBase_2D()
{
	//UE_LOG(LogTemp, Warning, TEXT("Game mode constructor"));
}

void AGameModeBase_2D::BeginPlay()
{
	Super::BeginPlay();

	Initialise();

	//testing 
	OpenLevelFor2DGame("L_LevelSelect");
	WidgetManager->ShowLoadingScreen();
}
void AGameModeBase_2D::Initialise()
{
	UE_LOG(LogTemp, Warning, TEXT("GameMode %s has loaded"), *this->GetName());
	
	//save manager load
	SaveManager = Cast<UGameSaveManager>(UGameplayStatics::GetGameInstance(this));
	if (!SaveManager)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find game instance save manager"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SaveManager %s has loaded"), *SaveManager->GetName());
	
	//level manager load
	//LevelManager = SaveManager->GetSubsystem<ULevelManager>();
	LevelManager = UGameplayStatics::GetGameInstance(this)->GetSubsystem<ULevelManager>();
	if (!LevelManager)
	{
		UE_LOG(LogTemp, Error, TEXT("Game mode cant find LevelManager"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("LevelManager %s has loaded"),*LevelManager->GetName());

	//widget manager load
	WidgetManager = Cast<AWidgetManagerHud>(UGameplayStatics::GetPlayerController(this,0)->GetHUD());
	if (!WidgetManager)
	{
		UE_LOG(LogTemp, Error, TEXT("Game mode cant find WidgetManagerHUD=%s"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("WidgetManager %s has loaded"), *WidgetManager->GetName());

}
void AGameModeBase_2D::OpenLevelFor2DGame(FName LevelName)
{
	LevelManager->OpenLevelFromManager(LevelName);
}

//handles UI 
//
