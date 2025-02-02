// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"
// creare uno slot con data asset che prende i dati di un oggetto ela quantità //

USTRUCT(Blueprintable)
struct FInventorySlot
{	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Category=Item)
	int Amount;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category=Item)
	UInventoryItemData* ItemData;
	
	
};

UCLASS( ClassGroup=(InventorySystem), meta=(BlueprintSpawnableComponent) )
class ESAME_ILARIASERGI_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UInventory();

protected:
	UPROPERTY(EditAnywhere,Category=Inventory)
	TArray<FInventorySlot> Items;
	
	virtual void BeginPlay() override;

public:	

	
	void AddItem(UInventoryItemData* Item, int Amount);
	
	void AddItem(AInventoryItemActor* Item,int Amount);
	
	//fvector per sapere dove droppare
	void DropItem(UInventoryItemData* Item, int Amount, FVector Location);
	

	FInventorySlot* GetSlotByData(UInventoryItemData* Item);

	UFUNCTION(blueprintCallable, Category="Inventory")
	FInventorySlot GetRandomSlot();
	
	void DropItem(int Index, int Amount, FVector Location);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
