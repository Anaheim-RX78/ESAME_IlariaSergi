// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
   
	
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoin::UpdateScore()
{
	UGameInstance* Instance = UGameplayStatics::GetGameInstance(GetWorld());
	UDropperGameInstance* DropperInstance = Cast<UDropperGameInstance>(Instance);
	ScoreManager->AddToScore(value, DropperInstance);
	//GEngine-> AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("TOTAL POINTS: %d"), DropperInstance -> PlayerScore));
	
}

int ACoin::GetValue()
{
	return value;
}




