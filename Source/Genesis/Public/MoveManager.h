// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Genesis/Move.h"
#include "Engine/DataTable.h"
#include "MoveManager.generated.h"

class APokemonBase;
struct FTypeModifier;

UCLASS()
class GENESIS_API UMoveManager : public UObject
{
	GENERATED_BODY()
	
	static UDataTable* DTMove;
	static UDataTable* DTTypeModifier;
public:
	/* Move is executed by BattleManager class
	*  that gets input from UI for the move that was 
	*  executed in order to inflict on the target */
	UFUNCTION(BlueprintCallable, Category = "MoveManager")
	static void Execute( APokemonBase* Target, APokemonBase* Attacker, const FName& MoveName);
	
	UMoveManager();
};
