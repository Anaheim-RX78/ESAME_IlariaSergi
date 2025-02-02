// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input.h"
#include "MainCharacter.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class ESAME_ILARIASERGI_API AMainCharacterController : public APlayerController
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere)
	AMainCharacter* MainCharacter;
	
	UPROPERTY(EditAnywhere, Category=input, meta=(AllowPrivateAccess=true))
	UInputAction* InputAction;

	UPROPERTY(EditAnywhere, Category=input, meta=(AllowPrivateAccess=true))
	UInput* InputMap;
	
	
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	
	UFUNCTION()
	void Jump( const FInputActionValue& Value);
	
	UFUNCTION()
	void Move( const FInputActionValue& Value);
	
	UFUNCTION()
	void Look( const FInputActionValue& Value);
	
	UFUNCTION()
	void Catch(const FInputActionValue& Value);
	
	UFUNCTION()
	void Activate( const FInputActionValue& Value);

	
	UFUNCTION()
	void UseAntidoto( const FInputActionValue& Value);

};
