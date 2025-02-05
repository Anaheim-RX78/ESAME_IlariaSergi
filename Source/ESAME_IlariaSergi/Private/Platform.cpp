// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform.h"

// Sets default values
APlatform::APlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RunningTime = 0.f;
	Speed = 1.f;
}

// Called when the game starts or when spawned
void APlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	//EndLocation = FVector(StartLocation.X+movementOnXAxis, StartLocation.Y+movementOnYAxis, StartLocation.Z);
}

// Called every frame
void APlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	float Alpha = (FMath::Sin(RunningTime) + 1.0f) / 2.0f;
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Alpha);
	SetActorLocation(NewLocation);
}
