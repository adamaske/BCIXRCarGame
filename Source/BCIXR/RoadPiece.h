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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
		TArray<class USceneComponent*> mObstaclePoints;
	int mObstacleAmount = 4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> mObstacles;
	TArray<class USceneComponent*> GetObstaclePoints();
	void SetObstacles(TArray<AActor*> obstacles);

	UFUNCTION(BlueprintCallable)
		void SetPoints(TArray<class USceneComponent*> points);
};
