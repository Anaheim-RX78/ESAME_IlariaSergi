// Fill out your copyright notice in the Description page of Project Settings.



#include "ESAME_IlariaSergi/Public/MainCharacter.h"

#include "AITestsCommon.h"
#include "Coin.h"
#include "DropperGameInstance.h"
#include "Inventory.h"
#include "PlayerInteractionComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("camera arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm-> TargetArmLength = 500.0f;
	SpringArm-> bUsePawnControlRotation = true;
	
	//creazione della camera
	Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("camera"));
	Camera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);
	
	InteractionComponent= CreateDefaultSubobject<UPlayerInteractionComponent>(TEXT("PlayerInteraction"));
	InteractionComponent->SetupAttachment(Camera);
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	
	Super::BeginPlay();

	//recupero il tempo del livello e lo salvo per reimpostarlo dopo il time out
	UGameInstance* Instance =UGameplayStatics::GetGameInstance(GetWorld());
	UDropperGameInstance* DropperInstance = Cast<UDropperGameInstance>(Instance);
	InitialLevelTime = DropperInstance->LevelTime;
	
	//recupero la posizione iniziale per reimpostarla dopo il time out
	InitialLocation = GetActorLocation();

	InitialSpeed=Speed;
	
	//resetto la game instance e il movimento del player
	InitGame();
	   
}
//funzione chiamata anche dopo il game over
void AMainCharacter::InitGame()
{
	//imposto il movimento al character
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	//rimetto l'actor sulla posizione iniziale di gioco
	SetActorLocation(InitialLocation);
	
	TimeOutShowing = false;

	//resetto la game instance
	UGameInstance* Instance =UGameplayStatics::GetGameInstance(GetWorld());
	UDropperGameInstance* DropperInstance = Cast<UDropperGameInstance>(Instance);

	if (DropperInstance)
	{
		//DropperInstance->MaxDepth = FMath::RandRange(0.0f, 1000.0F);
		//DropperInstance -> Attempts = 0;
		DropperInstance -> PlayerScore = 0;
		DropperInstance -> LevelTime = InitialLevelTime;
		DropperInstance -> LastCheckpointPosition = InitialLocation;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no game instance found"));
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//decrementa tempo di gioco
	UGameInstance* Instance =UGameplayStatics::GetGameInstance(GetWorld());
	UDropperGameInstance* DropperInstance = Cast<UDropperGameInstance>(Instance);
	DropperInstance->LevelTime -= DeltaTime;

	//quando finisco il tempo, se non sto mostrando il timeout
	//è vera solo al primo tick sul 0
	if (DropperInstance->LevelTime <= 0 && !TimeOutShowing)
	{
		GEngine-> AddOnScreenDebugMessage(-1, 5, FColor::Red, "TIME OUT");
		TimeOutShowing = true;
		GetCharacterMovement()->DisableMovement();
		//imposto un timer di 5 secondi qunado scade invoco initgame
		GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &AMainCharacter::InitGame, 5.0f, false);
	}

	//gestione della velocità (effetto mushroom)
	if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		if ( LastMushroomSeconds > 0 )
		{
			LastMushroomSeconds  = LastMushroomSeconds - DeltaTime;
		} else
		{
			LastMushroomSeconds = 0;
			Speed = InitialSpeed;
		}
		MovementComponent->MaxWalkSpeed = Speed;
		
	}
}

float AMainCharacter::GetSpeed()
{
	return Speed;
}

void AMainCharacter::SetSpeed(float NewSpeed)
{
	Speed = NewSpeed;
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMainCharacter::PrendiAntidoto()
{
	antidoti = antidoti +1;
}

void AMainCharacter::InvalidateMushroomEffect()
{
	if (antidoti >0 )
	{
		LastMushroomSeconds = 0;
		antidoti = antidoti-1;
	}
	
}

void AMainCharacter:: Respawn()
{
	SetSpeed(InitialSpeed);
	UGameInstance* Instance =UGameplayStatics::GetGameInstance(GetWorld());
	UDropperGameInstance* DropperInstance = Cast<UDropperGameInstance>(Instance);
	if (DropperInstance && DropperInstance -> LastCheckpointPosition!=InitialLocation)
	{
		SetActorLocation(DropperInstance -> LastCheckpointPosition);
	}
	else
	{
		InitGame();
	}
}

void AMainCharacter::SetMovementInput(const FVector2D& MovementInput)
{
	//AddMovementInput(GetActorForwardVector(),MovementInput.Y);
	//AddMovementInput(GetActorRightVector(),MovementInput.X);
	
	AddMovementInput(FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y), MovementInput.X);
	AddMovementInput(FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::X), MovementInput.Y);
	
}

void AMainCharacter::SetLookUpInput(const FVector2D& LookUpInput)
{
	AddControllerPitchInput(LookUpInput.Y);
	AddControllerYawInput(LookUpInput.X);
}
void AMainCharacter::SetLastMushroomSeconds(float NewLastMushroomSeconds)
{
	LastMushroomSeconds = NewLastMushroomSeconds;
}
