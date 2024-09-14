// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ingrained_Sandbox.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"


/**
 * 
 */
UCLASS()
class INGRAINED_SANDBOX_API UMySaveGame : public USaveGame
{

public :
	GENERATED_BODY()

	UPROPERTY()
	FStat_Struct  NegativePlayerStats[8];



};
