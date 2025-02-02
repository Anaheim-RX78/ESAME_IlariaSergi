// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "CatchInteractionComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent) )
class ESAME_ILARIASERGI_API UCatchInteractionComponent : public UCapsuleComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UCatchInteractionComponent();
};

