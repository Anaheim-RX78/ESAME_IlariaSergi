// Fill out your copyright notice in the Description page of Project Settings.


#include "ESAME_IlariaSergi/Public/MainCharacterController.h"

#include "EnhancedInputComponent.h"

void AMainCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	ULocalPlayer* LocalPlayer = GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMap->Context, 0);
	
	UEnhancedInputComponent* EnhancedInputComponent= Cast<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(InputMap->Action["Jump"], ETriggerEvent::Started,this, &AMainCharacterController::Jump);
	EnhancedInputComponent->BindAction(InputMap->Action["Move"], ETriggerEvent::Triggered,this,  &AMainCharacterController::Move);
	EnhancedInputComponent->BindAction(InputMap->Action["Look"], ETriggerEvent::Triggered,this,  &AMainCharacterController::Look);
	EnhancedInputComponent->BindAction(InputMap->Action["Activate"], ETriggerEvent::Started,this,  &AMainCharacterController::Activate);
	
	EnhancedInputComponent->BindAction(InputMap->Action["UseAntidoto"], ETriggerEvent::Started,this,  &AMainCharacterController::UseAntidoto);
	
}

void AMainCharacterController::OnPossess(APawn* InPawn)
{
	
	Super::OnPossess(InPawn);
	if (AMainCharacter* MainCharacterPawn = Cast<AMainCharacter>(InPawn))
	{
		MainCharacter= MainCharacterPawn;
	}
	
}

void AMainCharacterController::Jump(const FInputActionValue& Value)
{
	MainCharacter-> Jump();
}

void AMainCharacterController::Move(const FInputActionValue& Value)
{
	MainCharacter->SetMovementInput(Value.Get<FVector2D>());
}

void AMainCharacterController::Look(const FInputActionValue& Value)
{
	MainCharacter->SetLookUpInput(Value.Get<FVector2D>());
}

void AMainCharacterController::Catch(const FInputActionValue& Value)
{
	
}
void AMainCharacterController::Activate(const FInputActionValue& Value)
{
	MainCharacter->GetInteractionComponent()->Interact();
	
}

void AMainCharacterController::UseAntidoto(const FInputActionValue& Value)
{
	MainCharacter->InvalidateMushroomEffect();
}
