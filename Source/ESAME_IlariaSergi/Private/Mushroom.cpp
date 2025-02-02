// Fill out your copyright notice in the Description page of Project Settings.


#include "Mushroom.h"

#include <chrono>

// Sets default values
AMushroom::AMushroom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMushroom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMushroom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMushroom::GetScaleVelocity()
{
	return ScaleVelocity;
}

bool AMushroom::GetBonus()
{
	return bonus;
}

int AMushroom::GetSeconds()
{
	return Seconds;
	
}

