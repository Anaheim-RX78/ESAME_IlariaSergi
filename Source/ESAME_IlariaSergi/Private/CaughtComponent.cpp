// Fill out your copyright notice in the Description page of Project Settings.


#include "CaughtComponent.h"

// Sets default values for this component's properties
UCaughtComponent::UCaughtComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCaughtComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCaughtComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UCaughtComponent::GetInteractionLabel() const
{
	return InteractionLabel;
}

void UCaughtComponent::Interaction()
{
	GEngine-> AddOnScreenDebugMessage(-1, 5, FColor::Red, "Interaction");
	
	OnintercationStart();
	OnInteractionStartDelegate.Broadcast();
	GetOwner()->Destroy();
	
}

void UCaughtComponent::OnintercationStart()
{
	GEngine-> AddOnScreenDebugMessage(-1, 5, FColor::Red, "OnInteract");
}

