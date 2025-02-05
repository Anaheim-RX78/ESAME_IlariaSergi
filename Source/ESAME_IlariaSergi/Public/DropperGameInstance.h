// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DropperGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ESAME_ILARIASERGI_API UDropperGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Score");
	int PlayerScore=0;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category= "Score");
	float LevelTime=300;
	
	UPROPERTY(EditAnywhere,Category=score)
	int Attempts= 0;
	
	UPROPERTY(EditAnywhere,Category=Level)
	FString CurrentLevelIdentifier = "Level_01";
	
	UFUNCTION(BlueprintCallable)
	void OnLevelLoaded(FString LevelIdentifier);

	UPROPERTY(BlueprintReadWrite)
	FVector LastCheckpointPosition;
};
