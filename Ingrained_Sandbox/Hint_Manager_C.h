// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include "Boss_Spawner_C.h"
#include "Ingrained_Sandbox.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Hint_Manager_C.generated.h"


using namespace std;

UCLASS(Blueprintable , ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INGRAINED_SANDBOX_API UHint_Manager_C : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHint_Manager_C();

// PROPERTIES-----------------

	UPROPERTY()
		ABoss_Spawner_C*  SpawnedActor  ;

	UPROPERTY(BlueprintReadWrite)
		int id;

	UPROPERTY(BlueprintReadWrite)
	bool boss_spawned ;

	UPROPERTY()
	int global_hints_given ;

	
	UPROPERTY()
		FHints_ammount_Struct Category_Hints_Ammounts[9];

	UPROPERTY()
		FHint_Struct Shopkeeper_Hints[17];

	UPROPERTY()
		FHint_Struct Warriors_Hints[9];



// FUNCTIONS-----------------

	UFUNCTION(BlueprintCallable)
		bool Shopkeeper_Provide_Hint();

	UFUNCTION(BlueprintCallable)
		bool Warriors_Provide_Hint();

	UFUNCTION(BlueprintCallable)
		int Hint_Weight_Management();

	UFUNCTION(BlueprintCallable)
		int Get_id();
	


protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
