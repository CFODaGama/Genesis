// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Move.generated.h"

/**
 * 
 */
enum class EType;

USTRUCT(BlueprintType)
struct FMove : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	FString Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	FString Type;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	int32 Power;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	int32 PowerPoints;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	int32 Accuracy;
};