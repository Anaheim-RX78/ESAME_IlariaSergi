// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "PlayerInteractionComponent.h"
#include "Camera/CameraComponent.h"
//#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class ESAME_ILARIASERGI_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, Category=Movement)
	float Speed =500.0f;
	
	float InitialSpeed;

	FVector InitialLocation;
	
    float LastMushroomSeconds;
	
	UPROPERTY(EditAnywhere, Category=Movement)
	float JumpForce= 1000.0f;
	
	UPROPERTY(EditAnywhere, Category=Camera)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category=Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category=Inventory)
	UInventory* Inventory;

	UPROPERTY(EditAnywhere, Category=Interaction)
	UPlayerInteractionComponent* InteractionComponent;

	//Gestione timer per tempo di gioco
	float InitialLevelTime;
	bool TimeOutShowing;
	FTimerHandle MovementTimerHandle;
	
	int antidoti;
	
	virtual void BeginPlay() override;
	void Tick(float DeltaTime);
	
	UFUNCTION(BlueprintCallable)
    void Respawn();

	void InitGame();
	

public:
	float GetSpeed();
	void SetSpeed(float NewSpeed);
	void SetLastMushroomSeconds(float NewLastMushroomSeconds);
	
	UPlayerInteractionComponent* GetInteractionComponent() const  { return InteractionComponent;}
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void PrendiAntidoto();
	
	void InvalidateMushroomEffect();

	//UFUNCTION(BlueprintImplementableEvent)
	//void ShowWidget();
	
	void SetMovementInput(const FVector2D& MovementInput);
	void SetLookUpInput(const FVector2D& LookUpInput);
};
	