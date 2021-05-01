// Jon Reis 2021-04-28.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LevelManager.generated.h"


/**
 * Manages all level activities in game 
 */
UCLASS(Blueprintable,Abstract)
class PROJECT__1_API ULevelManager : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void RemoveLoadingScreen();

	
	FName CurrentLevelName= FName(TEXT(""));;

public:

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
