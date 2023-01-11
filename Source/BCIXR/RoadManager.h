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
	float mSpeed = 200.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float mMaxSpeed = 300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float mMinSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float mAcceleration = 5.f;
	UFUNCTION(BlueprintCallable)
	void Accelerate(float value);
	//not in use
	FVector mStart	{0,0,0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int mPiecesBehindPlayerBeforeDespawn = 2;
	void ResetObstaclesOnPiece(ARoadPiece* road);
};
