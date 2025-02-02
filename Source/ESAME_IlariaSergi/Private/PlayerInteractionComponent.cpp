// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"

#include "InteractableComponent.h"

// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UPlayerInteractionComponent::CheckInteractionRange()
{
	FHitResult HitResult;

	GetWorld()->LineTraceSingleByChannel(HitResult, GetComponentLocation(), GetComponentLocation() + (GetForwardVector() * InteractionDistance), InteractionChannel);
	
	//GetWorld()->LineTraceSingleByProfile(HitResult, GetComponentLocation(), GetForwardVector() * InteractionDistance, InteractionProfile);

	AActor* HitActor = HitResult.GetActor();

	if (HitActor == nullptr)
	{
		CurrentInteractable = nullptr;
		return;
	} 
	
	UInteractableComponent* Component = HitResult.GetActor()->GetComponentByClass<UInteractableComponent>();

	if (CurrentInteractable == nullptr && Component)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Emerald, TEXT("Interactable Found"));
		CurrentInteractable = Component;
	}
	else if (CurrentInteractable && Component && Component != CurrentInteractable)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Emerald, TEXT("Interactable Replaced"));
		CurrentInteractable = Component;
	}
}


// Called every frame
void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CheckInteractionRange();
}

void UPlayerInteractionComponent::Interact()
{
	if (CurrentInteractable == nullptr) return;

	CurrentInteractable->Interact(FInteractionPayload{GetOwner()});
}


