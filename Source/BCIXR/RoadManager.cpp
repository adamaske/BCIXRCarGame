// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadManager.h"
#include "RoadPiece.h"
// Sets default values
ARoadManager::ARoadManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoadManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoadManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRunning) {
		CheckRoads();

		MoveRoads(DeltaTime);
	}
}

void ARoadManager::CreateRoad()
{
	FVector start{ 0,0,0 };
	for (int i{ 0 }; i < 5; i++) {
		//Create piece
		auto piece = GetWorld()->SpawnActor(mRoadBP);
		auto rp = Cast<ARoadPiece>(piece);
		mPieces.Add(rp);
		//Set location
		FVector loc = start;
		loc.X = (rp->GetLength()) * i;
		piece->SetActorLocation(loc);
	}
}

void ARoadManager::StartRoads()
{
	bRunning = true;
}

void ARoadManager::StopRoads()
{
	bRunning = false;
}

void ARoadManager::ResetRoads()
{
	FVector start{ 0,0,0 }; // Sets all location to their starting point
	for (int i{0}; i < mPieces.Num(); i++)
	{
		FVector loc = start;
		loc.Y = (mPieces[i]->GetLength()) * i;
		mPieces[i]->SetActorLocation(loc);
		mPieces[i]->ResetRoadPiece();
	}
}

void ARoadManager::MoveRoads(float deltaTime)
{
	for (auto road : mPieces) {
		road->AddActorLocalOffset(FVector{ -mSpeed * deltaTime, 0, 0 });
	}
}

void ARoadManager::CheckRoads()
{
	for (auto road : mPieces) {
		FVector loc = road->GetActorLocation();
		if (loc.X <= -10000) {
			//Reset the road piece
			FVector newLoc{ (road->GetLength() * mPieces.Num())-10000,0,0};
			road->SetActorLocation(newLoc);
			road->ResetRoadPiece();
		}
	}
}


