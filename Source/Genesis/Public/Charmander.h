// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PokemonBase.h"
#include "Charmander.generated.h"

/**
 * 
 */
UCLASS()

class GENESIS_API ACharmander : public APokemonBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION() virtual void LevelUp() override;

protected:
	virtual void BeginPlay() override;
};
