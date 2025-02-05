// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform.generated.h"

UCLASS()
class ESAME_ILARIASERGI_API APlatform : public AActor
{
	GENERATED_BODY()
	
public:
	APlatform();
	
protected:
	UPROPERTY(VisibleAnywhere)
	FVector StartLocation;
	
	UPROPERTY(EditAnywhere)
	FVector EndLocation;
	
	UPROPERTY()
	float RunningTime;
	
	UPROPERTY(EditAnywhere)
	float Speed;
	
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
