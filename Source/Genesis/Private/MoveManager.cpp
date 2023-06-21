// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveManager.h"

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
	if(DTMove)
	{
		const FMove* Move = DTMove->FindRow<FMove>(MoveName, TEXT("Pokemon MoveSet Context"), true);
		if(Move)
		{
			const FString = static_cast<FString>(Move->Type) + static_cast<FString>(Target->Type);
			FTypeModifier* TypeModifier = DTTypeModifier->FindRow<FTypeModifier>(static_cast<FName>(TwoTypeName), TEXT("Pokemon Type Context"), true);
			if(TypeModifier)
			{
				// ( ( ( (2 * AttackerLevel / 5) + 2) * MovePower * (AttackerAttackStat / TargetDefence) ) / 50 + 2) * TypeModifier
				((((2 * Attacker->GetLevel() / 5) + 2) * Move->Power * (Attacker->GetAttack() / Target->GetDefence())) / 50 + 2) * TypeModifier->Amount;
			}
		}
	}

	
}



