// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss_Spawner_C.h"
#include <Misc/OutputDeviceNull.h>



// Sets default values
ABoss_Spawner_C::ABoss_Spawner_C()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	/// Hint ammounts list initialize 
	Category_Hints_Ammounts[0] = { 1  , TEXT("Rare"), 0 };
	Category_Hints_Ammounts[1] = { 2  , TEXT("High-Status"), 0 };
	Category_Hints_Ammounts[2] = { 3  , TEXT("Immoral"), 0 };
	Category_Hints_Ammounts[3] = { 4  , TEXT("Warriors") , 0 };
	Category_Hints_Ammounts[4] = { 5  , TEXT("Magicians"), 0 };
	Category_Hints_Ammounts[5] = { 6  , TEXT("Shopkeepers"), 0 };
	Category_Hints_Ammounts[6] = { 7  , TEXT("Commoner"), 0 };
	Category_Hints_Ammounts[7] = { 8  , TEXT("Misc"), 0 };
	Category_Hints_Ammounts[8] = { 9  , TEXT("Explorers"), 0 };
	Category_Hints_Ammounts[9] = { 10 , TEXT("In need"), 0 };

}

void ABoss_Spawner_C::Spawn_Boss(int id)
{
	My_id = id;


	UE_LOG(LogTemp, Warning, TEXT("Spawn Boss Method Called id : %d ------------------------------------------"), id);

	if ((id >= 0) && (id <= 9))
	{
		if (Category_Hints_Ammounts[id].FDescription == "Warriors")
		{
			UE_LOG(LogTemp, Warning, TEXT("Now boss Will be spawned By warriors---------------------  "));

			// Set values to the FVector variable
			MyVector.X = 8100.0f;
			MyVector.Y = -3545.0f;
			MyVector.Z = 1237.0f;


		}
		if (Category_Hints_Ammounts[id].FDescription == "Shopkeepers")
		{

			UE_LOG(LogTemp, Warning, TEXT("Now boss Will be spawned By Shopkeepers---------------------  "));
			// Inside a class or function
	
			// Set values to the FVector variable
			MyVector.X = -7021.0f;
			MyVector.Y = -3535.0f;
			MyVector.Z = 1357.0f;


		}
	}

	if ((id < 0) || (id > 9))
	{

		UE_LOG(LogTemp, Warning, TEXT("Weight Managment Error------------------------------------------  "));
	}

	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(TEXT("SpawnBossPawn"), ar, NULL, true);

}

// Called when the game starts or when spawned
void ABoss_Spawner_C::BeginPlay()
{
	Super::BeginPlay();
	
	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(TEXT("SpawnBossPawn"), ar, NULL, true);

}

// Called every frame
void ABoss_Spawner_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

