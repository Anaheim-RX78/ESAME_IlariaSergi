// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaughtComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBasicInteractionDelegate);

UCLASS( ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent) )
class ESAME_ILARIASERGI_API UCaughtComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCaughtComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="interaction")
	FString InteractionLabel;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FString GetInteractionLabel()const;

	void Interaction();
	
	UPROPERTY(BlueprintAssignable)
	FBasicInteractionDelegate OnInteractionStartDelegate;
	
	virtual void OnintercationStart();

};