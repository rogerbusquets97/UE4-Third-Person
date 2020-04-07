// Fill out your copyright notice in the Description page of Project Settings.
#include "FPSCharacter.h"
#include "EngineGlobals.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	UE_LOG(LogTemp, Warning, TEXT("EEEEEEh"));
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Axis
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	
	//Actions
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
}

void AFPSCharacter::MoveForward(float value)
{
	FRotator Rotator = GetControlRotation();
	float roll;
	float pitch;
	float yaw;

	UKismetMathLibrary::BreakRotator(Rotator, roll, pitch, yaw);

	FRotator NewRotator = UKismetMathLibrary::MakeRotator(0.f, 0.f, yaw);
	FVector Direction = UKismetMathLibrary::GetForwardVector(NewRotator);
	AddMovementInput(Direction, value);
}

void AFPSCharacter::MoveRight(float value)
{
	FRotator Rotator = GetControlRotation();
	float roll;
	float pitch;
	float yaw;

	UKismetMathLibrary::BreakRotator(Rotator, roll, pitch, yaw);

	FRotator NewRotator = UKismetMathLibrary::MakeRotator(0.f, 0.f, yaw);
	FVector Direction = UKismetMathLibrary::GetRightVector(NewRotator);
	AddMovementInput(Direction, value);
}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}
