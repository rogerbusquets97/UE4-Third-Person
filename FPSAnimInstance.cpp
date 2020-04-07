// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAnimInstance.h"
#include "EngineGlobals.h"
#include "Engine.h"

UFPSAnimInstance::UFPSAnimInstance()
{
	speed = 0.0;
	InAir = false;
}

void UFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	APawn* OwnerActor = TryGetPawnOwner();

	if (OwnerActor != nullptr)
	{
		speed = OwnerActor->GetVelocity().Size();
		InAir = OwnerActor->GetMovementComponent()->IsFalling();
	}
}
