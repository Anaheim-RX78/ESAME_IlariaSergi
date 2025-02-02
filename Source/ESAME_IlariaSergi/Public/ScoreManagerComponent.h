// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DropperGameInstance.h"
#include "Components/ActorComponent.h"
#include "ScoreManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESAME_ILARIASERGI_API UScoreManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreManagerComponent();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//UDropperGameInstance* DropperInstance;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void AddToScore(int points,UDropperGameInstance* DropperInstance);
	
	
};
