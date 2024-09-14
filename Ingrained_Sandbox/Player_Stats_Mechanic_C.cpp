// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Stats_Mechanic_C.h"
#include "MySaveGame.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UPlayer_Stats_Mechanic_C::UPlayer_Stats_Mechanic_C()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Negative Stats Initialization
	NegativePlayerStats[0] = { 1, TEXT("Apathetic"), 0.0 };
	NegativePlayerStats[1] = { 2, TEXT("Suspicious"), 0.0 };
	NegativePlayerStats[2] = { 3, TEXT("Dishonest"), 0.0 };
	NegativePlayerStats[3] = { 4, TEXT("Greedy"), 0.0 };
	NegativePlayerStats[4] = { 5, TEXT("Cruel"), 0.0 };
	NegativePlayerStats[5] = { 6, TEXT("Malicious"), 0.0 };
	NegativePlayerStats[6] = { 7, TEXT("Hostile"), 0.0 };
	NegativePlayerStats[7] = { 8, TEXT("Hypocritical"), 0.0 };

	//Positive Stats Initialization
	PositivePlayerStats[0] = { 1, TEXT("Generosity"), 0.0 };
	PositivePlayerStats[1] = { 2, TEXT("Peaceful"), 0.0 };
	PositivePlayerStats[2] = { 3, TEXT("Faithful"), 0.0 };
	PositivePlayerStats[3] = { 4, TEXT("Self-Control"), 0.0 };
	PositivePlayerStats[4] = { 5, TEXT("Friendly"), 0.0 };
	PositivePlayerStats[5] = { 6, TEXT("Kindness"), 0.0 };
	PositivePlayerStats[6] = { 7, TEXT("Intuitive"), 0.0 };


	//Test Change entry 

	
}

bool UPlayer_Stats_Mechanic_C::CheckNegativeStatsCriteria(float Apathetic, float Suspicious, float Dishonest, float Greedy, float Cruel, float Malicious, float Hostile, float Hypocritical)
{
	if ( (NegativePlayerStats[0].FValue < Apathetic)      &&
		 (NegativePlayerStats[1].FValue < Suspicious)     &&
		 (NegativePlayerStats[2].FValue < Dishonest   )   &&
		 (NegativePlayerStats[3].FValue < Greedy)         &&
		 (NegativePlayerStats[4].FValue < Cruel)          && 
		 (NegativePlayerStats[5].FValue < Malicious   )   &&
		 (NegativePlayerStats[6].FValue < Hostile)        &&
		 (NegativePlayerStats[7].FValue < Hypocritical))
	{
		
		for (FStat_Struct& entry : NegativePlayerStats)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s - %f "), *entry.FDescription, entry.FValue);
		}
		return true;

	}
	
	return false;
}


void UPlayer_Stats_Mechanic_C::AddNegativeStats(float Apathetic, float Suspicious, float Dishonest, float Greedy,float Cruel, float Malicious, float Hostile,float Hypocritical)
{

	NegativePlayerStats[3].FValue += Greedy;
	NegativePlayerStats[4].FValue += Cruel;
	NegativePlayerStats[5].FValue += Malicious;


	for (FStat_Struct& entry : NegativePlayerStats)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s - %f "), *entry.FDescription, entry.FValue);
	}

}

void UPlayer_Stats_Mechanic_C::SaveStats()
{

	UE_LOG(LogTemp, Warning, TEXT(" Saving Stats .... "));
	//Create an instance of our savegame class
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	//Pass NegativeStats To SaveGame Object
	SaveGameInstance->NegativePlayerStats[0] = this->NegativePlayerStats[0];
	SaveGameInstance->NegativePlayerStats[1] = this->NegativePlayerStats[1];
	SaveGameInstance->NegativePlayerStats[2] = this->NegativePlayerStats[2];
	SaveGameInstance->NegativePlayerStats[3] = this->NegativePlayerStats[3];
	SaveGameInstance->NegativePlayerStats[4] = this->NegativePlayerStats[4];
	SaveGameInstance->NegativePlayerStats[5] = this->NegativePlayerStats[5];
	SaveGameInstance->NegativePlayerStats[6] = this->NegativePlayerStats[6];
	SaveGameInstance->NegativePlayerStats[7] = this->NegativePlayerStats[7];



	if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Save2"), 0) != false)
	{
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Save2"), 0);
		UE_LOG(LogTemp, Warning, TEXT(" Saving Stats .... "));
		UE_LOG(LogTemp, Warning, TEXT("Negative Stat to save %f "), SaveGameInstance->NegativePlayerStats[4].FValue);

	}



}

void UPlayer_Stats_Mechanic_C::LoadStats()
{


	//Create an instance of our savegame class
	//UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	if (UGameplayStatics::DoesSaveGameExist(TEXT("Save2"), 0) != false)
	{

		if (UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Save2"), 0)))
		{
			NegativePlayerStats[0] = LoadGameInstance->NegativePlayerStats[0];
			NegativePlayerStats[1] = LoadGameInstance->NegativePlayerStats[1];
			NegativePlayerStats[2] = LoadGameInstance->NegativePlayerStats[2];
			NegativePlayerStats[3] = LoadGameInstance->NegativePlayerStats[3];
			NegativePlayerStats[4] = LoadGameInstance->NegativePlayerStats[4];
			NegativePlayerStats[5] = LoadGameInstance->NegativePlayerStats[5];
			NegativePlayerStats[6] = LoadGameInstance->NegativePlayerStats[6];
			NegativePlayerStats[7] = LoadGameInstance->NegativePlayerStats[7];

			//UE_LOG(LogTemp, Warning, TEXT("wtf %s! "), LoadGameInstance->NegativePlayerStats[0].FValue);
			//LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Save1"), 0));
		}



		UE_LOG(LogTemp, Warning, TEXT("Game Loaded! "));

	}



}



// Called when the game starts
void UPlayer_Stats_Mechanic_C::BeginPlay()
{
	Super::BeginPlay();

	for (FStat_Struct& entry : NegativePlayerStats)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s - %f "), *entry.FDescription, entry.FValue);
	}

	// ...
	
}


// Called every frame
void UPlayer_Stats_Mechanic_C::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

