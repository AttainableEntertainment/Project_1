// Jon Reis 2021-04-28.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LevelManager.generated.h"


/**
 * Manages all level activities in game 
 */
UCLASS(Abstract,Blueprintable)
class PROJECT__1_API ULevelManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:

	//Functions
	UFUNCTION()
	void RemoveLoadingScreen();
	UFUNCTION()
	void UnLoadLevel(FName LevelName);
	UFUNCTION()
	void LoadLevel();

	void InitalizeLoadingScreen();

	//Variables

	FName CurrentLevelName="";
	FName LastLevelName = "";
	//for handling latency of simultaneous load/unload of levels  
	FLatentActionInfo LatentAction;

public:
	ULevelManager();

	//Variables

	UPROPERTY(EditAnywhere, Instanced, Category = "Widgets")
	UUserWidget* LoadingScreen;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	float LoadingScreenDisplayTime=2.0f;
	
	//Functions
	
	/** Opens a level and allows manager to handle internal workings 
	*@param LevelName	 The name of the level to open
	*/
	UFUNCTION(BlueprintCallable, Category = "Level Manager")
	void OpenLevelFromManager(FName LevelName);
};
