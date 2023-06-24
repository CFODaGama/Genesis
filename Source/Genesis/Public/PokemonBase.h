// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PokemonBase.generated.h"

UCLASS()
class GENESIS_API APokemonBase : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	APokemonBase();
	UFUNCTION()
	FString GetType() const;
	UFUNCTION()
	int32 GetAttack() const;
	UFUNCTION()
	int32 GetDefence() const;
	UFUNCTION()
	int32 GetLvl() const;
	UFUNCTION()
	void ApplyDamage(const int DamageAmt);


	

	// Called every frame

   
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)TArray<FString> Type;
	UPROPERTY(EditAnywhere)int Speed;
	UPROPERTY(EditAnywhere)int Defense;
	UPROPERTY(EditAnywhere)int SpecialAttack;
	UPROPERTY(EditAnywhere)int SpecialDefense;
	UPROPERTY(EditAnywhere)int Health;
	UPROPERTY(EditAnywhere)int Attack;
	UPROPERTY(EditAnywhere)int Lvl;
	UPROPERTY(EditAnywhere)int MaxXp = 100;
	UPROPERTY(EditAnywhere)int CurrentXp;
	UPROPERTY() int32 BattleStats = FMath::RandRange(1,4);
	
	virtual void LvlUp() {}


};

