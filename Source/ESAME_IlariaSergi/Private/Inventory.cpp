// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

#include "InventoryItemActor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInventory::AddItem(UInventoryItemData* Item, int Amount)
{
	{	if (FInventorySlot* SlotPtr = GetSlotByData(Item))
	{
		SlotPtr->Amount += Amount;
	}
		FInventorySlot Slot;
		Slot.ItemData = Item;
		Slot.Amount = Amount;
		Items.Add (Slot);
	}

}

void UInventory::AddItem(AInventoryItemActor* Item, int Amount)
{
	AddItem(Item->ItemData, Amount);
	Item-> Destroy();
	
}

void UInventory::DropItem(UInventoryItemData* Item, int Amount, FVector Location)
{
	for (int i=0; i<Amount; i++)
	{
		GetWorld()->SpawnActor<AInventoryItemActor>(Item->Item ,Location, FRotator::ZeroRotator);
	}
}

FInventorySlot* UInventory::GetSlotByData(UInventoryItemData* Item)
{
	for (FInventorySlot& Slot : Items)
	{
		if (Slot.ItemData == Item)
		{
			return &Slot;
		}
	}
	return nullptr; 

}

FInventorySlot UInventory::GetRandomSlot()
{
	//l'indice massimo che posso estrarre è di num(dimensione array)-1
	int maxIndex = Items.Num()-1;
	int randomIndex =  UKismetMathLibrary::RandomIntegerInRange(0, maxIndex);
	return Items[randomIndex];
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

