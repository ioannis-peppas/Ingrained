// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Ingrained_Sandbox.generated.h"


USTRUCT(BlueprintType)
struct FStat_Struct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Fid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString  FDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FValue;

	
};

USTRUCT(BlueprintType)
struct FHint_Struct
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Fid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString  FDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FValid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FProbability;

};

USTRUCT(BlueprintType)
struct FHints_ammount_Struct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Fid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString  FDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Fammount;
};

