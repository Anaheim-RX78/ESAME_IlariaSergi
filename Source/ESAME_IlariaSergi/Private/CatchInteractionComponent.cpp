// Fill out your copyright notice in the Description page of Project Settings.


#include "CatchInteractionComponent.h"

#include "CaughtComponent.h"
#include "Coin.h"
#include "MainCharacter.h"
#include "Mushroom.h"

void UCatchInteractionComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Comportamento per tutti gli actor che hanno CaughtComponent
   
	
	if (OtherActor==nullptr) {return;}
	UCaughtComponent* InteractComponent = OtherActor->FindComponentByClass<UCaughtComponent>() ;
	if (InteractComponent != nullptr)
	{
		InteractComponent->	Interaction();
	}
	
	// Comportamento specifico per gli Item che aggiungono punteggio
	if ( ACoin* caughtCoin = Cast<ACoin>(OtherActor))
	{
		caughtCoin -> UpdateScore();
	}
	
	if ( AMushroom* caughtMushroom = Cast<AMushroom>(OtherActor))  
	{
		if (AMainCharacter* myCharacter = Cast<AMainCharacter>(GetOwner()) )
		{
			if (caughtMushroom->GetBonus())
			{
			     float currentSpeed = myCharacter->GetSpeed();
				 float newSpeed = currentSpeed* caughtMushroom-> GetScaleVelocity();
				myCharacter->SetSpeed(newSpeed);
				myCharacter-> SetLastMushroomSeconds(caughtMushroom->GetSeconds());
			}
		}
		
	}
	
}

UCatchInteractionComponent::UCatchInteractionComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &UCatchInteractionComponent::OnOverlapBegin);
}
