// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data_2DGame.generated.h"

/*Data for chapters*/
USTRUCT(BlueprintType)
struct FChapterData
{
    GENERATED_BODY()


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChapterData")
    TSoftObjectPtr<UWorld> ChapterWorld;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChapterData")
    bool bIsChapterLocked;

};

/**
 * Holds data for a 2d game mode like levels,UI,Transition Screens
 */
UCLASS(Abstract, Blueprintable)
class PROJECT__1_API UData_2DGame : public UGameInstanceSubsystem
{
    GENERATED_BODY()
        //TODO: Add struct 

public:
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChapterData")
        FChapterData ChapterData;

};

USTRUCT(BlueprintType)
struct FMyStruct
{
    GENERATED_BODY()

        //~ The following member variable will be accessible by Blueprint Graphs:
        // This is the tooltip for our test variable.
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Variables")
        int32 MyIntegerMemberVariable;

    //~ The following member variable will be not accessible by Blueprint Graphs:
    int32 NativeOnlyMemberVariable;

    /**~
    * This UObject pointer is not accessible to Blueprint Graphs, but
    * is visible to UE4's reflection, smart pointer, and garbage collection
    * systems.
    */
    UPROPERTY()
        UObject* SafeObjectPointer;
};
