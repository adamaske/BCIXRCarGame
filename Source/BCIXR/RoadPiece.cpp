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
	
}

// Called every frame
void ARoadPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (mObstacles.Num() > 0) {
		for (int i = 0; i < mObstacles.Num(); i++) {
			mObstacles[i]->SetActorLocation(mObstaclePoints[i]->GetComponentLocation());
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
}

TArray<USceneComponent*> ARoadPiece::GetObstaclePoints()
{
	return mObstaclePoints;
}

void ARoadPiece::SetObstacles(TArray<AActor*> obstacles)
{
	mObstacles = obstacles;
}

void ARoadPiece::SetPoints(TArray<class USceneComponent*> points)
{
	mObstaclePoints = points;
}

