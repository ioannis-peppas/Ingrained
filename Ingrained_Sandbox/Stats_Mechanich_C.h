// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ingrained_Sandbox.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stats_Mechanich_C.generated.h"


UCLASS(Blueprintable)
class INGRAINED_SANDBOX_API AStats_Mechanich_C : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStats_Mechanich_C();

	
	UPROPERTY()
	FStat_Struct  PositivePlayerStats[7];
	UPROPERTY()
	FStat_Struct  NegativePlayerStats[8];



	UFUNCTION(BlueprintCallable)
	void AddNegativeStats();

	UFUNCTION(BlueprintCallable)
	void SaveStats();

	UFUNCTION(BlueprintCallable)
		void LoadStats();
	 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
