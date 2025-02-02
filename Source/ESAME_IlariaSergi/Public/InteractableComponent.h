// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"

USTRUCT(BlueprintType)
struct FInteractionPayload 
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly)
	AActor* Interactor;

	UPROPERTY(BlueprintReadOnly)
	FVector Location;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionHandler, FInteractionPayload, Payload);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESAME_ILARIASERGI_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category= "interaction")
	FString InteractionName;
	
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintAssignable)
	FInteractionHandler OnInteract;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void Interact(FInteractionPayload Payload);

	UFUNCTION(BlueprintCallable)
	FString GetInteractionName() const;
};
