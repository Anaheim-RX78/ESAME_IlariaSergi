// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItemData.generated.h"
//Forward declaration al posto dell'include= questo oggetto esiste nell'engine a questo nome (non dice metodi cc.)

class AInventoryItemActor;
/**
 * 
 */
UCLASS()
class ESAME_ILARIASERGI_API UInventoryItemData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category= Itemdetails);
	FString PrettyName;

	UPROPERTY(EditAnywhere,Category= Itemdetails);
	FString Description;
	
	UPROPERTY(EditAnywhere,Category= Itemdetails);
	float Weight;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere, Category = item)
	TSubclassOf<AInventoryItemActor> Item;
	// definire il type tramite subclassof per spawnare un oggetto dal suo template e non l'istanza.
	//riferimento unico della classe del actor che dobbiamo spawnare, ma quando andiamo a spawnare in scena può essere un istanza diversa
	
	
};
