// Fill out your copyright notice in the Description page of Project Settings.


#include "Hint_Manager_C.h"
#include "Boss_Spawner_C.h"
#include <random>

// Sets default values for this component's properties
UHint_Manager_C::UHint_Manager_C()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Shopkeeper Hints initialization
	Shopkeeper_Hints[0]   = { 1,  TEXT("Behind the second tree after the crazy house"),true, 0.7 };
	Shopkeeper_Hints[1]   = { 2,  TEXT("Right outside my old village"),true,0.65 };
	Shopkeeper_Hints[2]   = { 3,  TEXT("How should i know, ask my vendors"),true,0.60};
	Shopkeeper_Hints[3]   = { 4,  TEXT("Ive heard the wishpers at the tavern too"),true, 0.65 };
	Shopkeeper_Hints[4]   = { 5,  TEXT("Its weird that you ask. I saw it yesterday by the lake's dock"),true, 0.30 };
	Shopkeeper_Hints[5]   = { 6,  TEXT("You must be crazy for trying to go. I like you. On top of the western hill after you pass the main city. You didnt hear it from me "),true, 0.20 };
	Shopkeeper_Hints[6]   = { 7,  TEXT("Go to the sea's dock and ask the officer. He definitly knows"),true, 0.10 };
	Shopkeeper_Hints[7]   = { 8,  TEXT("Right by the big bridge covering the river that ends in the lake.Now please, dont get me involved "),true, 0.15 };
	Shopkeeper_Hints[8]   = { 9,  TEXT("Come on now. Everyone saw it yesterday behind the stain church.Havent you heard?"),true, 0.10 };
	Shopkeeper_Hints[9]   = { 10, TEXT("Where did you come from ? Everybody knows that its residing in the northen rift"),true, 0.160 };
	Shopkeeper_Hints[10]  = { 11, TEXT("Ask the horse vendor.He meets a lot of travelers and definitly knows."),true, 0.150 };
	Shopkeeper_Hints[11]  = { 12, TEXT("A customer told me yesterday he saw it one mile straight south from here.Poor guy he was traumatized."),true, 0.120 };
	Shopkeeper_Hints[12]  = { 13, TEXT("Leave me alone please.Its in the center of the forrest. Shame on you for asking withought knowing what others have been through "),true, 0.130 };
	Shopkeeper_Hints[13]  = { 14, TEXT("hahaha. If you kill it then you owe me to buy a great shord twice. its in the seashore of the eastern front"),true, 0.150 };
	Shopkeeper_Hints[14]  = { 15, TEXT("Ask the military governor firend.Its their business. Not mine. He definitly know though"),true, 0.10 };
	Shopkeeper_Hints[15]  = { 16, TEXT("Im loving the heroism. If you come back alive you come by and buy something.My dog was found dead close to the volcano.Its definitly there.My Dogg was a furious fighter"),true, 0.0 };
	Shopkeeper_Hints[16]  = { 17, TEXT("Get some food because you have to travell to the southern Mountain.Good luck.I really Hope you are the chosen saviour"),true, 0.5 };


	//Warriors Hints initialization
	Warriors_Hints[0] = { 1,  TEXT("Find the three dead sholdiers by the sea"),true, 0.7 };
	Warriors_Hints[1] = { 2,  TEXT("Mind you business citizen. And do not go the top of the western mountain. Its illigal"),true,0.65 };
	Warriors_Hints[2] = { 3,  TEXT("Hmm once i head the captain talk about that place you are looking for."),true,0.60 };
	Warriors_Hints[3] = { 4,  TEXT("Talking about this case should not be allowed by my co worekrs. Did they tell you to go the the river ? Do not try to!"),true, 0.65 };
	Warriors_Hints[4] = { 5,  TEXT("Its weird that you ask. I saw it yesterday by the giant village"),true, 0.30 };
	Warriors_Hints[5] = { 6,  TEXT("You must be crazy for trying to go. I like you. The army could use people like you. Find the captain of the 'Smaragdia' Ship. Hell tell you"),true, 0.20 };
	Warriors_Hints[6] = { 7,  TEXT("There is a map drawn behind the curch on the floor. How has nobody noticed this ?"),true, 0.10 };
	Warriors_Hints[7] = { 8,  TEXT("Keep walking Citizen!!!. Leave before i arrest you. Keep walking.And hey go north. You will know when to stop"),true, 0.15 };
	Warriors_Hints[8] = { 9,  TEXT("My companions where killed yesterday. I dont care anymore. If you have a deathwish you can just go to the western hill"),true, 0.10 };


	/// Hint ammounts list initialize
	Category_Hints_Ammounts[0] = { 1  , TEXT("Rare"), 0  };
	Category_Hints_Ammounts[1] = { 2 , TEXT("High-Status"), 0  };
	Category_Hints_Ammounts[2] = { 3 , TEXT("Immoral"), 0  };
	Category_Hints_Ammounts[3] = { 4 , TEXT("Warriors") , 0 };
	Category_Hints_Ammounts[4] = { 5 , TEXT("Magicians"), 0  };
	Category_Hints_Ammounts[5] = { 6 , TEXT("Shopkeepers"), 0  };
	Category_Hints_Ammounts[6] = { 7 , TEXT("Commoner"), 0  };
	Category_Hints_Ammounts[7] = { 8 , TEXT("Misc"), 0  };
	Category_Hints_Ammounts[8] = { 9 , TEXT("Explorers"), 0  };
	Category_Hints_Ammounts[9] = { 10 , TEXT("In need"), 0 };

	boss_spawned = false;
	global_hints_given = 0;


}

//Should only be called from shopkeeper actors
bool UHint_Manager_C::Shopkeeper_Provide_Hint()
{
	int listlength = sizeof(Shopkeeper_Hints) / sizeof(Shopkeeper_Hints[0]);


	// Create a random device to seed the random number generator
	std::random_device rd;

	// Create a random number engine
	std::mt19937 rng(rd());

	// Create a uniform distribution
	std::uniform_int_distribution<int> uni(1, listlength);

	// Generate a random integer between 0 and 17
	int randomHint = uni(rng);

	// Create a uniform distribution for floating-point numbers
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	// Generate a random float
	float randomProbability = dist(rng);

	for (FHint_Struct& entry : Shopkeeper_Hints)
	{
		if ((entry.Fid == randomHint) && (entry.FValid == true) )
		{
			if (randomProbability >= entry.FProbability) {

				UE_LOG(LogTemp, Warning, TEXT("%s  "), *entry.FDescription); // Provide Hint 
				entry.FValid = false; // Set as given hint
				Category_Hints_Ammounts[6].Fammount++;
				global_hints_given ++ ;
				return true;
				break; // exit loop
			}
			else
			{
				// Calculate random Hint Again for next search 
				randomHint = uni(rng);
			}
		}
	}

	return false;

}

//Should only be called from warrior actors
bool UHint_Manager_C::Warriors_Provide_Hint()
{
	int listlength = sizeof(Warriors_Hints) / sizeof(Warriors_Hints[0]);


	// Create a random device to seed the random number generator
	random_device rd;

	// Create a random number engine
	mt19937 rng(rd());

	// Create a uniform distribution
	uniform_int_distribution<int> uni(1, listlength);

	// Generate a random integer between 0 and 17
	int randomHint = uni(rng);

	// Create a uniform distribution for floating-point numbers
	uniform_real_distribution<float> dist(0.0f, 1.0f);

	// Generate a random float
	float randomProbability = dist(rng);

	for (FHint_Struct& entry : Warriors_Hints)
	{
		if ((entry.Fid == randomHint) && (entry.FValid == true))
		{
			if (randomProbability >= entry.FProbability) {

				UE_LOG(LogTemp, Warning, TEXT("%s  "), *entry.FDescription); // Provide Hint 
				entry.FValid = false; // Set as given hint
				Category_Hints_Ammounts[4].Fammount++;
				global_hints_given ++;
				return true;
				break; // exit loop
			}
			else
			{
				// Calculate random Hint Again for next search 
				randomHint = uni(rng);
			}
		}
	}

	return false;

}

//Manage Weight of hint lists
int UHint_Manager_C::Hint_Weight_Management() {

	int selected_list_id = 0,
		max = Category_Hints_Ammounts[0].Fammount,
		count = 0;

	for (int i = 0; i < 10 ; i++) {
		if (Category_Hints_Ammounts[i].Fammount > max) {
			max = Category_Hints_Ammounts[i].Fammount;
			selected_list_id = i-1;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (Category_Hints_Ammounts[i].Fammount == max)
		{
			count++;    // Increment the count for equal maximum values
		}
	}

	/// Search for Same ammount of hints given
	if (count >1 ) {
		for (int i = 0; i < 10 ; i++)
		{
			for (int j = i + 1; j <= 9; j++)
			{
				if (
					  (Category_Hints_Ammounts[i].Fammount == max)  &&
					  (Category_Hints_Ammounts[i].Fammount == Category_Hints_Ammounts[j].Fammount)
					)
				{
					/// Found same of hints
					selected_list_id = i-1;  //Select the higher weight hintlist id
				}
			}
		}
	}
	return selected_list_id;
}

int UHint_Manager_C::Get_id()
{
	return id;
}

// Called when the game starts
void UHint_Manager_C::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHint_Manager_C::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if ( (global_hints_given >= 4) && ( boss_spawned == false))
	{
		

		UWorld* World = GetWorld(); // Assuming this function is within a class that has access to the world
		FActorSpawnParameters SpawnParams;

		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		id = Hint_Weight_Management();
		boss_spawned = true;
		

		if (World)
		{
			
		 SpawnedActor = World->SpawnActor<ABoss_Spawner_C>(ABoss_Spawner_C::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);

			if (SpawnedActor)
			{
				SpawnedActor->Spawn_Boss(id);
				//SpawnedActor->Spawn_Boss_Event();
			}
		}

	}



}



