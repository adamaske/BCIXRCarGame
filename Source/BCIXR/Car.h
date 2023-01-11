// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Car.generated.h"

UCLASS()
class BCIXR_API ACar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mMeshComp;

	UPROPERTY(EditAnywhere)
		float mSpeed  = 1.f;
	UFUNCTION(BlueprintCallable)
	void MoveRight(float value);
	UFUNCTION(BlueprintCallable)
	void MoveForward(float value);
	
	UPROPERTY(EditAnywhere)
		float mAcceleration = 1.f;
	UPROPERTY(EditAnywhere)
		float mAccelerationRate = 1.f;
	UPROPERTY(EditAnywhere)
		float mMaxAcceleration = 2.f; 
	UPROPERTY(EditAnywhere)
		float mMinAcceleration = 0.f;
	UPROPERTY(EditAnywhere)
		float mDecceleration = 0.4f;
	UFUNCTION(BlueprintCallable)
		void Accelerate(float value);
	UFUNCTION(BlueprintCallable)
		void Deccelerate(float value);
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void HitByObstacle(class UObstacleComponent* obstacle);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int mHealth = 5;
private:
	float mDeltaTime = 0;

};
