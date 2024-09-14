// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ingrained_Sandbox.h"
#include "Boss_Spawner_C.generated.h"

UCLASS(Blueprintable)
class INGRAINED_SANDBOX_API ABoss_Spawner_C : public AActor
{
	GENERATED_BODY()

public:



	// Sets default values for this actor's properties
	ABoss_Spawner_C();

	UPROPERTY()
		FHints_ammount_Struct Category_Hints_Ammounts[10];


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int My_id;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector MyVector; // Declaration

	UFUNCTION()
		void Spawn_Boss(int id);



	/** Broadcasts whenever the layer changes */
	/*DECLARE_EVENT(FLayerViewModel, FSpawn_Boss)*/
	UFUNCTION(BlueprintImplementableEvent)
		void Spawn_Boss_Event();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
