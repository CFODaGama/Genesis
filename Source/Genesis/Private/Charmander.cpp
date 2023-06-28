// Fill out your copyright notice in the Description page of Project Settings.


#include "Charmander.h"


ACharmander::ACharmander()
{
	// Set Variables
	Types           = {"Fire"};
	Speed			= 65;
	Defense			= 43;
	SpecialAttack	= 60;
	SpecialDefense	= 50;
	Health			= 39;
	Attack			= 52;

	UMoveManager::TeachMove(this, FName("Scratch"));
}


