// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAnimInstance.h"
#include "EngineGlobals.h"
#include "Engine.h"
#include "FPSCharacter.h"

UFPSAnimInstance::UFPSAnimInstance()
{
	speed = 0.0;
	InAir = false;
	InCombat = false;
}

void UFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	AFPSCharacter* OwnerActor = static_cast<AFPSCharacter*>(TryGetPawnOwner());

	if (OwnerActor != nullptr)
	{
		speed = OwnerActor->GetVelocity().Size();
		InAir = OwnerActor->GetMovementComponent()->IsFalling();
		InCombat = OwnerActor->WeaponEquipped;
	}
}
