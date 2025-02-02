// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LuckyBox.generated.h"

UCLASS()
class ESAME_ILARIASERGI_API ALuckyBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALuckyBox();
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool activated;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool GetActivated();

	UFUNCTION(BlueprintCallable)
	void SetActivated(bool b);
	
  //  UFUNCTION(BlueprintCallable)
//	int getRandomItem();
};
