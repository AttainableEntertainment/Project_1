// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/LevelStreaming.h"


void ULevelManager::OpenLevelFromManager(FName LevelName)
{
	if (LoadingScreen)
	{
		LoadingScreen->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("Widget Found for level manager"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Widget Found for level manager"))
	}

	//timer to wait for loading of level 
	FTimerHandle TimerHandle;
	FTimerDelegate EnableDelegate = FTimerDelegate::CreateUObject(this,&ULevelManager::RemoveLoadingScreen);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, EnableDelegate,LoadingScreenDisplayTime,false);

	//if other level is already loaded, unload the level
	if (CurrentLevelName!="")
	{
		UE_LOG(LogTemp, Warning, TEXT("Unloading %s" ), *(CurrentLevelName.ToString()));
		UGameplayStatics::UnloadStreamLevel(this, CurrentLevelName,FLatentActionInfo(),false);
	}
	
	CurrentLevelName = LevelName;
	UE_LOG(LogTemp, Warning, TEXT("loading %s"), *(CurrentLevelName.ToString()));
	UGameplayStatics::LoadStreamLevel(this, LevelName, true, false, FLatentActionInfo());
	

}
void ULevelManager::RemoveLoadingScreen()
{
	
	LoadingScreen->RemoveFromParent();
}
