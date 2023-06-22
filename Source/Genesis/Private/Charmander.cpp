// Fill out your copyright notice in the Description page of Project Settings.


#include "Charmander.h"

void ACharmander::BeginPlay()
{
	Super::BeginPlay();

	// Set Variables
	Type            = "Fire";
	Speed			= 65;
	Defense			= 43;
	SpecialAttack	= 60;
	SpecialDefense	= 50;
	Health			= 39;
	Attack			= 52;
	Lvl			= 1;
	CurrentXp       = 0;
} 
	//improve stats
void ACharmander::LvlUp()
{
	Speed			+= FMath::RandRange(1,2);
	Health			+= FMath::RandRange(1,5);
	Defense			+= BattleStats;
	SpecialAttack	+= BattleStats;
	SpecialDefense	+= BattleStats;
	Attack			+= BattleStats;
	Lvl			++;
	CurrentXp        = 0;
}
 


