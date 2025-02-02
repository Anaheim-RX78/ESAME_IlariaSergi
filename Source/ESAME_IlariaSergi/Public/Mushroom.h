// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mushroom.generated.h"

UCLASS()
class ESAME_ILARIASERGI_API AMushroom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMushroom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
    UPROPERTY(EditAnywhere)
	bool bonus;

	UPROPERTY(EditAnywhere)
	int Seconds;

	UPROPERTY(EditAnywhere)
	float ScaleVelocity;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetScaleVelocity();

	bool GetBonus();

	int GetSeconds();
	
	
};
