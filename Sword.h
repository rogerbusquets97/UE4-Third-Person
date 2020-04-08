// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API ASword : public ABaseWeapon
{
	GENERATED_BODY()

	ASword();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
