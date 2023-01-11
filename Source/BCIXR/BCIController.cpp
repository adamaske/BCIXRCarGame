// Fill out your copyright notice in the Description page of Project Settings.


#include "BCIController.h"
#include "RoadManager.h"
#include "Car.h"
void ABCIController::OnPossess(APawn* PawnToPossess) {
	//Find if its a car
	mCar = Cast<ACar>(PawnToPossess);
	if (!mCar) {
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, TEXT("BCIController : Not a Car"));
		return;
	}
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("BCIController : Possesed Car"));

	//Create road manager
	mRoadManager = Cast<ARoadManager>(GetWorld()->SpawnActor(mRoadManagerBP));
	if (!mRoadManager) {
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, TEXT("BCIController : Road Manager not created"));
	}
	mRoadManager->CreateRoad();
	mRoadManager->StartRoads();
}

void ABCIController::RecieveBCIInput(FString command, float value)
{
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("BCIController : Recieved BCI Input : " + command + " with value :"));

	if (!mCar) {
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, TEXT("BCIController : No car"));
		return;
	}

	//Is it a command?

	FString neutral = "/com/neutral";
	FString left = "/com/left";
	FString right = "/com/right";
	FString forward = "/com/forward";
	FString backward = "/com/backward";
	if (command == neutral) {
		//Brake the car?
	}
	if (command == left) {
		//
		mCar->MoveRight(value);
	}
	if (command == right) {
		mCar->MoveRight(-value);
	}
	if (command == forward) {
		//mCar->MoveForward(value);
		mRoadManager->Accelerate(value);
	}
	if (command == backward) {
		//mCar->MoveForward(-value);

		mRoadManager->Accelerate(-value);
	}
	
}
