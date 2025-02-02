// Fill out your copyright notice in the Description page of Project Settings.

#include "LuckyBox.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ALuckyBox::ALuckyBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALuckyBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALuckyBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ALuckyBox::GetActivated()
{
	return activated;
}

void ALuckyBox::SetActivated(bool b)
{
	activated = b;
}

/*int ALuckyBox::getRandomItem()
{
	if(activated)
	{
		return 0;
	}
	else
	{
		activated=true;
		return UKismetMathLibrary::RandomIntegerInRange(1, 3);
	}
		
}
*/
