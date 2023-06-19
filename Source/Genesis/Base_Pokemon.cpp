// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Pokemon.h"

// Sets default values
ABase_Pokemon::ABase_Pokemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABase_Pokemon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase_Pokemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

