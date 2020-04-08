// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSAnimInstance.generated.h"

UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class FPSPROJECT_API UFPSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFPSAnimInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
	float speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
	bool InAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
	bool InCombat;
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
