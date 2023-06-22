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

	static ConstructorHelpers::FObjectFinder<UDataTable> DTTypeModifierFinder(TEXT("C:/Users/chirp/Documents/Unreal Projects/Genesis/Content/_MyContent/Data/DT_Move.uasset"));
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
			const FString TwoTypeName = Move->Type + Target->GetType();
			if(const FTypeModifier* TypeModifier = DTTypeModifier->FindRow<FTypeModifier>(static_cast<FName>(TwoTypeName), TEXT("Pokemon Type Context"), true))
			{
				const float Damage = ((((2 * Attacker->GetLvl() / 5) + 2) * Move->Power * (Attacker->GetAttack() / Target->GetDefence())) / 50 + 2) * TypeModifier->Amount;
				Target->ApplyDamage(Damage);
			}
		}
	}

	
}



