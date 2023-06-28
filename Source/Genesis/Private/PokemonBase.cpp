// Fill out your copyright notice in the Description page of Project Settings.


#include "PokemonBase.h"

#include "MoveManager.h"

APokemonBase::APokemonBase()
{
	// Init Variables
	Lvl = 1;
	CurrentXp = 0;
	MoveManager = UMoveManager::StaticClass();

	// Set Components
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	PokemonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PokemonMesh"));
	PokemonMesh->SetupAttachment(SceneComponent);
	
}

TArray<FString>& APokemonBase::GetTypes()
{
	return Types;
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

void APokemonBase::LvlUp()
{
	Speed			+= FMath::RandRange(1,2);
	Health			+= FMath::RandRange(1,5);
	Defense			+= FMath::RandRange(1,4);
	SpecialAttack	+= FMath::RandRange(1,4);
	SpecialDefense	+= FMath::RandRange(1,4);
	Attack			+= FMath::RandRange(1,4);
	Lvl				++;
	CurrentXp        = 0;
}




