// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManagerHud.h"

#include "Blueprint/UserWidget.h"
#include "Components/Widget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void AWidgetManagerHud::ShowWidget(UUserWidget* Widget)
{
	if (!Widget)
	{
		UE_LOG(LogTemp, Error, TEXT("Widget is not able to show cause its null"));
		return;
	}
	Widget->AddToViewport(0);
	CurrentWidget = Widget;
	
	//FInputModeGameAndUI InputMode;
	//InputMode.SetHideCursorDuringCapture(true);
	//InputMode.SetWidgetToFocus(TSharedRef < SWidget > TakeWidget());

	//UGameplayStatics::GetPlayerController(this,0)->SetInputMode(InputMode);
	//UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->DisableInput(UGameplayStatics::GetPlayerController(this, 0));
	//GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());
	//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	//UGameplayStatics::GetPlayerPawn(this,0)->DisableInput(PlayerController);
}
//oid AWidgetManagerHud::SetInputMode()

void AWidgetManagerHud::ShowLoadingScreen()
{
	ShowWidget(LoadingScreen);
}