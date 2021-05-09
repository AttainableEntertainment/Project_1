// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSaveManager.h"

UGameSaveManager::UGameSaveManager()
{
	UE_LOG(LogTemp, Warning, TEXT("Created class name =%s"), *(this->GetFName().ToString()));
}

