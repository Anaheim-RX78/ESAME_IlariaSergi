// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreManagerComponent.h"

#include "DropperGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UScoreManagerComponent::UScoreManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UScoreManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}

void UScoreManagerComponent::AddToScore(int points,UDropperGameInstance* DropperInstance)
{
	
	if (DropperInstance)
	{
		DropperInstance->PlayerScore += points;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no game instance found"));
	}
	
}


// Called every frame
void UScoreManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

