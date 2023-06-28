// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Genesis/Move.h"
#include "PokemonBase.generated.h"

class UMoveManager;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS()
class GENESIS_API APokemonBase : public AActor
{
	GENERATED_BODY()

	
public:
	
	APokemonBase();
	
	UFUNCTION()
	TArray<FString>& GetTypes();
	UFUNCTION()
	int32 GetAttack() const;
	UFUNCTION()
	int32 GetDefence() const;
	UFUNCTION()
	int32 GetLvl() const;
	UFUNCTION()
	void ApplyDamage(const int DamageAmt);
   
protected:
	
#pragma region Variables
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon")
	TArray<FString> Types;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon")
	TArray<FMove> MoveSet;
	
#pragma region TSubClassOf

	TSubclassOf<UMoveManager> MoveManager;
	
#pragma endregion TSubClassOf
	
#pragma region Components

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Components")
	USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Components")
	USkeletalMeshComponent* PokemonMesh;
	
#pragma endregion Components

#pragma region XP
	
	static constexpr int MaxXp = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pokemon")
	int Lvl;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pokemon")
	int CurrentXp;
	
#pragma endregion XP
	
#pragma region Stats
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Stats")
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Stats")
	int Attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Stats")
	int SpecialAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Stats")
	int Defense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Stats")
	int SpecialDefense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon|Stats")
	int Speed;
	
#pragma endregion Stats

#pragma endregion General
	
	UFUNCTION(BlueprintCallable, Category = "Pokemon Functions")
	void LvlUp();
	


};

