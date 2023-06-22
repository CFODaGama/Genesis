// Fill out your copyright notice in the Description page of Project Settings.


#include "PokemonBase.h"





// Sets default values
APokemonBase::APokemonBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void APokemonBase::BeginPlay()
{
	Super::BeginPlay();
	
} 

FString APokemonBase::GetType() const
{
	return Type;
}

int32 APokemonBase::GetAttack() const
{
	return Attack;
}

int32 APokemonBase::GetDefence() const
{
	return Defense;
}

int32 APokemonBase::GetLvl() const
{
	return Lvl;
}

void APokemonBase::ApplyDamage(const int DamageAmt)
{
	Health -= DamageAmt;
}





