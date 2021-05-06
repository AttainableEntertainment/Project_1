// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/LevelStreaming.h"

ULevelManager::ULevelManager()
{
	UE_LOG(LogTemp, Warning, TEXT("Created class name =%s"), *(this->GetFName().ToString()));
	
	LatentAction.CallbackTarget = this;
	LatentAction.ExecutionFunction = "LoadLevel";
	LatentAction.UUID = 1;
	LatentAction.Linkage = 0;
}
void ULevelManager::OpenLevelFromManager(FName LevelName)
{
	CurrentLevelName = LevelName;
	InitalizeLoadingScreen();

	if (LastLevelName != "")
	{
		UnLoadLevel(LastLevelName);
		LastLevelName = LevelName;
		return;
	}

	LoadLevel();
	LastLevelName = LevelName;
}
void ULevelManager::InitalizeLoadingScreen()
{
	if (!LoadingScreen)
	{
		UE_LOG(LogTemp, Error, TEXT("No Widget Found for level manager"));
		return;
	}

	//TODO Attach this to UI manager
	LoadingScreen->AddToViewport();

	FTimerHandle TimerHandle;
	FTimerDelegate EnableDelegate = FTimerDelegate::CreateUObject(this, &ULevelManager::RemoveLoadingScreen);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, EnableDelegate, LoadingScreenDisplayTime, false);
}
void ULevelManager::UnLoadLevel(FName LevelName)
{
	UE_LOG(LogTemp, Warning, TEXT("Unloading %s"), *(LevelName.ToString()));
	UGameplayStatics::UnloadStreamLevel(this, LevelName, LatentAction, false);	
}
void ULevelManager::LoadLevel()
{
	UE_LOG(LogTemp, Warning, TEXT("loading %s"), *(CurrentLevelName.ToString()));
	UGameplayStatics::LoadStreamLevel(this, CurrentLevelName, true, false, FLatentActionInfo());
}
void ULevelManager::RemoveLoadingScreen()
{
	LoadingScreen->RemoveFromParent();
}
