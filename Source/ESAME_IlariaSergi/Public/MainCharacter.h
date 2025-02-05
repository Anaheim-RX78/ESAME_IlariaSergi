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
	
	UPROPERTY(EditAnywhere, Category=Movement)
	float JumpForce= 1000.0f;
	
	UPROPERTY(EditAnywhere, Category=Camera)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category=Camera)
	USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, Category=Interaction)
	UPlayerInteractionComponent* InteractionComponent;
	
	int antidoti;
	
	float InitialSpeed;

	FVector InitialLocation;
	
	//da decrementare a ogni tick fino a quando diventa zero
	//quando arriva zero rimposto la initalspeed
	float LastMushroomSeconds;
	
	//Gestione timer per tempo di gioco
	
	//tempo del livello che prendo dalla game instance
	//da decrementare ongi tick
	float InitialLevelTime;
	
	//true quando il tempo scade e mostro il messaggio di game over
	bool TimeOutShowing;
	
	//timer di 5 secondi dopo il game over prima di ripartire
	FTimerHandle MovementTimerHandle;
	
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

	//chiamata bp sulla lcukybox
	UFUNCTION(BlueprintCallable)
	void PrendiAntidoto();
	
	//reimposta initialspeed e lastmushroomseconds=0
	void InvalidateMushroomEffect();
	
	void SetMovementInput(const FVector2D& MovementInput);
	void SetLookUpInput(const FVector2D& LookUpInput);
};
	