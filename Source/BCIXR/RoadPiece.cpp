// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadPiece.h"

// Sets default values
ARoadPiece::ARoadPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

