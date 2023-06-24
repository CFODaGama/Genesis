// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveManager.h"
#include "PokemonBase.h"
#include "TypeModifier.h"



UDataTable* UMoveManager::DTMove = nullptr;
UDataTable* UMoveManager::DTTypeModifier = nullptr;

UMoveManager::UMoveManager()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DTMoveFinder(TEXT("C:/Users/chirp/Documents/Unreal Projects/Genesis/Content/_MyContent/Data/DT_Move.uasset"));
	if(DTMoveFinder.Succeeded())
	{
		DTMove = DTMoveFinder.Object;
	}
	
	// Find TypeModifierTable

	static ConstructorHelpers::FObjectFinder<UDataTable> DTTypeModifierFinder(TEXT("C:/Users/chirp/Documents/Unreal Projects/Genesis/Content/_MyContent/Data/DT_TypeModifier.uasset"));
	if(DTTypeModifierFinder.Succeeded())
	{
		DTTypeModifier = DTTypeModifierFinder.Object;
	}
}

void UMoveManager::Execute(APokemonBase* Target, APokemonBase* Attacker, const FName& MoveName)
{
	if(DTMove && DTTypeModifier)
	{
		if(const FMove* Move = DTMove->FindRow<FMove>(MoveName, TEXT("Pokemon MoveSet Context"), true))
		{
			if(const FTypeModifier* TypeModifierRow = DTTypeModifier->FindRow<FTypeModifier>(static_cast<FName>(Move->Type), TEXT("Pokemon Type Context"), true))
			{
				const float TypeModifierValue = *(TypeModifierRow->TypeModifiers.Find(Target->GetType()));
				const float Damage = ((((2 * Attacker->GetLvl() / 5) + 2) * Move->Power * (Attacker->GetAttack() / Target->GetDefence())) / 50 + 2) * TypeModifierValue;
				Target->ApplyDamage(Damage);
			}
		}
	}

	
}



