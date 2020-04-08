// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseWeapon.h"
#include "FPSCharacter.generated.h"

class UCharacterMovementComponent;

UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void StartSprint();

	UFUNCTION()
	void StopSprint();

	UFUNCTION()
	void EquipWeapon();

	UFUNCTION(BlueprintCallable)
	void SpawnWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Generic")
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Generic")
	float WalkSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Generic")
	float RunSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Generic")
	TSubclassOf<class ABaseWeapon> Weapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Generic")
	ABaseWeapon* BaseWeapon;

	UPROPERTY(VisibleAnywhere)
	bool WeaponEquipped;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Generic")
	FName ArmedSocket;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Generic")
	FName UnnarmedSocket;
};
