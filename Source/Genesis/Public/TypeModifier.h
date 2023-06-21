// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TypeModifier.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FTypeModifier : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Type Modifer")
	float Amount;
};
