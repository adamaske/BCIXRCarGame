// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadPiece.generated.h"



UCLASS()
class BCIXR_API ARoadPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadPiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetLength();
	float GetWidth();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mLength = 2000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mWidth = 500;

	void ResetRoadPiece();

	//Obstacles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AActor>> mObstacleBPs; //Blueprint prefabs

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> mObstacles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> mActiveObstacles;
	//This will be the length of the offsetpoints, if the 0 index is = -1, 
	//when iterating trhough the offset points, -1 in this array means there is no obstacle attached
	//if the idnex contains 3, then this (i) offset point is controlling the 3 idnex of the obstacles
	TArray<int> mObstacleIndexToOffsetPoint;
	//Scramble the obstacles
	void ResetObstacles();

	void SetObstacles(TArray<AActor*> obstacles);

	//Set to -1 to not use the override, dont use more than obstacles.num 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int mObstacleAmountOverride = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> mObstaclePointOffsets = { {0,0,0}, {0,0,0},{0,0,0}, {0,0,0} };
	//Returns mPoints, mPoints.Num-1 is treated like the max amount of obstacles
	TArray<FVector> GetObstacleOffsets();
	void SetEnableAllObstacles(bool enabled);
	void SetEnableObstacle(AActor* obs, bool enabled);
	
};
