// Fill out your copyright notice in the Description page of Project Settings.
#include "FPSCharacter.h"
#include "EngineGlobals.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include"Sword.h"
#include "Engine/World.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementComponent = static_cast<UCharacterMovementComponent*>(GetMovementComponent());
	WalkSpeed = 150.f;
	RunSpeed = 375.f;

	MovementComponent->MaxWalkSpeed = WalkSpeed;

	ArmedSocket = FName("WeaponSocket");
	UnnarmedSocket = FName("UnnarmedWeaponSocket");
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
	WeaponEquipped = false;
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

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFPSCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFPSCharacter::StopSprint);

	PlayerInputComponent->BindAction("EquipWeapon", IE_Released, this, &AFPSCharacter::EquipWeapon);
}

void AFPSCharacter::SpawnWeapon()
{
	if (Weapon)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;

			const USkeletalMeshSocket* socket = GetMesh()->GetSocketByName("UnnarmedWeaponSocket");
			BaseWeapon = world->SpawnActor<ABaseWeapon>(Weapon, socket->GetSocketTransform(GetMesh()), SpawnParameters);

			if (BaseWeapon)
			{
				BaseWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, UnnarmedSocket);
			}
		}
	}
}

void AFPSCharacter::MoveForward(float value)
{
	FRotator Rotator = GetControlRotation();

	FRotator NewRotator = UKismetMathLibrary::MakeRotator(0.f, 0.f, Rotator.Yaw);
	FVector Direction = UKismetMathLibrary::GetForwardVector(NewRotator);
	AddMovementInput(Direction, value);
}

void AFPSCharacter::MoveRight(float value)
{
	FRotator Rotator = GetControlRotation();

	FRotator NewRotator = UKismetMathLibrary::MakeRotator(0.f, 0.f, Rotator.Yaw);
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

void AFPSCharacter::StartSprint()
{
	MovementComponent->MaxWalkSpeed = RunSpeed;
}

void AFPSCharacter::StopSprint()
{
	MovementComponent->MaxWalkSpeed = WalkSpeed;
}

void AFPSCharacter::EquipWeapon()
{
	if (BaseWeapon)
	{
		if (WeaponEquipped)
		{
			WeaponEquipped = false;
			BaseWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, UnnarmedSocket);
		}
		else
		{
			WeaponEquipped = true;
			BaseWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, ArmedSocket);
		}
	}
}
