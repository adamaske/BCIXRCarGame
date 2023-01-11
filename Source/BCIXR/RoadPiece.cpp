// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadPiece.h"

// Sets default values
ARoadPiece::ARoadPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void ARoadPiece::BeginPlay()
{
	Super::BeginPlay();
	//Currently the max amount of obstacles is 1 per offsetpoint
	for (int i = 0; i < mObstaclePointOffsets.Num(); i++) {
		mActiveObstacles.Add(0);
		//All the points are now associated with the 0th obstacle
		mObstacleIndexToOffsetPoint.Add(-1);
		//Chooses a random blueprint
		mObstacles.Add(GetWorld()->SpawnActor(mObstacleBPs[0]));
		SetEnableObstacle(mObstacles[i], false);
	}
	
	
}

// Called every frame
void ARoadPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 0; i < mObstaclePointOffsets.Num(); i++) {
		//This being -1 means the point dont have a obstacle associated with it
		if (mObstacleIndexToOffsetPoint[i] != -1) {
			//Since there is a obstacle associated with this offset, we move that obstacle index to this offset position
			mObstacles[mObstacleIndexToOffsetPoint[i]]->SetActorLocation(GetActorLocation() + mObstaclePointOffsets[i]);
		}
	}
}

float ARoadPiece::GetLength()
{
	return mLength;
}

float ARoadPiece::GetWidth()
{
	return mWidth;
}

void ARoadPiece::ResetRoadPiece()
{
	ResetObstacles();
}

TArray<FVector> ARoadPiece::GetObstacleOffsets()
{
	return mObstaclePointOffsets;
}

void ARoadPiece::ResetObstacles()
{
	//This is missing choosing random 
	//Disables all of them first
	//Im just not bothering check for who to enable and disabled, this could be done more effictently
	SetEnableAllObstacles(false);
	//Sets them all to -1, so only the active ones become changed to the index of the obstacle later
	for (int i = 0; i < mObstacleIndexToOffsetPoint.Num(); i++) {
		mObstacleIndexToOffsetPoint[i] = -1;
	}
	//Choose a random amount of obstacles to spawn this round
	int amount = mObstacleAmountOverride == -1 ? rand() % (mObstacles.Num()+1) : mObstacleAmountOverride;
	TArray<int> inds;
	for (int i = 0; i < mObstaclePointOffsets.Num(); i++) {
		inds.Add(i);
	}
	//We want to spawn "amount" amount of obstacles
	for (int i = 0; i < amount; i++) {
		//Get a random index of the inds
		int ind = rand() % inds.Num();
		//Removes it from the pool of offsets
		//inds.RemoveAt(ind);
		//This should proably be choosen to a random one of the obstacles and removes it from the pool but i wont bother right now
		SetEnableObstacle(mObstacles[i], true);
		//Attaching the obstacle to a offset
		mObstacleIndexToOffsetPoint[inds[ind]] = i;
		inds.RemoveAt(ind);
	}
}

void ARoadPiece::SetEnableAllObstacles(bool enabled) {
	for (auto obs : mObstacles) {
		obs->SetActorHiddenInGame(!enabled);
		obs->SetActorEnableCollision(enabled);
		obs->SetActorTickEnabled(enabled);
	}
}

void ARoadPiece::SetEnableObstacle(AActor* obs, bool enabled) {
	obs->SetActorHiddenInGame(!enabled);
	obs->SetActorEnableCollision(enabled);
	obs->SetActorTickEnabled(enabled);
}

void ARoadPiece::SetObstacles(TArray<AActor*> obstacles)
{
	mObstacles = obstacles;
}

