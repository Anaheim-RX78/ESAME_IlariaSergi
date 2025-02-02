// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnhancedInputSubsystems.h"
#include "Input.generated.h"


/**
 * 
 */
UCLASS(Blueprintable)
class ESAME_ILARIASERGI_API UInput : public UDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, Category=input)
	UInputMappingContext* Context;
	UPROPERTY(EditAnywhere,category=input)
	TMap<FString,UInputAction*>Action;
};
