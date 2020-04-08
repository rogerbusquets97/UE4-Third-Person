// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "Components/SkeletalMeshComponent.h"

ASword::ASword()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASword::BeginPlay()
{
	Super::BeginPlay();
}

void ASword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}