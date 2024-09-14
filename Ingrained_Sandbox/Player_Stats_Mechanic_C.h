// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ingrained_Sandbox.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player_Stats_Mechanic_C.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INGRAINED_SANDBOX_API UPlayer_Stats_Mechanic_C : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UPlayer_Stats_Mechanic_C();

	UPROPERTY()
		FStat_Struct  PositivePlayerStats[7];
	UPROPERTY()
		FStat_Struct  NegativePlayerStats[8];


	UFUNCTION(BlueprintCallable)
		void AddNegativeStats(float Apathetic, float Suspicious, float Dishonest, float Greedy, float Cruel, float Malicious, float Hostile, float Hypocritical);

	UFUNCTION(BlueprintCallable)
		bool CheckNegativeStatsCriteria(float Apathetic, float Suspicious, float Dishonest, float Greedy, float Cruel, float Malicious, float Hostile, float Hypocritical);


	UFUNCTION(BlueprintCallable)
		void SaveStats();

	UFUNCTION(BlueprintCallable)
		void LoadStats();


protected:

	// Called when the game starts

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
