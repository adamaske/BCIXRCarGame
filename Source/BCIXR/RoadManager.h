// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadManager.generated.h"

UCLASS()
class BCIXR_API ARoadManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Roads
	void CreateRoad();
	void StartRoads();
	void StopRoads();
	void ResetRoads();
	void MoveRoads(float deltaTime);
	void CheckRoads();
	//Blueprint of the road piece
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ARoadPiece> mRoadBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ARoadPiece*> mPieces;
	//Is the road moving?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRunning = false;
	//How fast is the road moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mSpeed = 100.f;

	//not in use
	FVector mStart	{0,0,0};
	FVector mEnd	{-10000,0,0};

	//Obstacles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<AActor>> mObstacleBPs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> mObstacles;

};
