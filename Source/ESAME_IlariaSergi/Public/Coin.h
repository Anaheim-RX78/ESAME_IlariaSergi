// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CaughtComponent.h"
#include "ScoreManagerComponent.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class ESAME_ILARIASERGI_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties")
	int value;

    UScoreManagerComponent* ScoreManager;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(Blueprintable)
	void UpdateScore();

	UFUNCTION(BlueprintCallable, Category="Properties")
	int GetValue();
	
	
};
