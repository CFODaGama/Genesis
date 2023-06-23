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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	int32 Power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	int32 PowerPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	int32 Accuracy;
};