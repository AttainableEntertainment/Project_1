// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget2D_Base.h"
#include "Components/Button.h"
#include "Blueprint/WidgetTree.h"

UUserWidget2D_Base::UUserWidget2D_Base(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UserWidget_2D_Base Constructed"));
	
	
}
bool UUserWidget2D_Base::Initialize()
{
	Super::Initialize();
	UE_LOG(LogTemp, Warning, TEXT("UserWidget_2D_Base Initialized"));

	//todo- add sound and handle gamepad input for all buttons, expose sound 

	//gets all gamepad buttons in widget and sets variable
	TArray<UWidget*> ChildWidgets;
	UWidgetTree::GetChildWidgets(GetRootWidget(), ChildWidgets);
	

	for (UWidget* Child : ChildWidgets)
	{
		if (!ensure(Child!= nullptr)) return true;
		if (Child->GetClass() == UButton::StaticClass())
		{
			Buttons.Add(Cast<UButton>(Child));
		}
	}
	return true;
}

void UUserWidget2D_Base::NativeConstruct()
{
	
	//GetWorld()->GetTimerManager().SetTimer(TimeHandle,0.2,true, );
}

void UUserWidget2D_Base::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
}

