// Fill out your copyright notice in the Description page of Project Settings.


#include "Car.h"

// Sets default values
ACar::ACar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//mMeshComp->OnComponentBeginOverlap.Add(this, &ACar::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mDeltaTime = DeltaTime;

	Deccelerate(mDecceleration);
}

// Called to bind functionality to input
void ACar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACar::MoveRight(float value)
{
	AddActorLocalOffset(FVector(mSpeed* value * mDeltaTime * mAcceleration, 0, 0) * GetActorRightVector());
	Accelerate(abs(value));
}

void ACar::MoveForward(float value)
{
	AddActorLocalOffset(FVector(0, mSpeed * value * mDeltaTime * mAcceleration, 0) * -GetActorForwardVector());
	Accelerate(value);
}

void ACar::Accelerate(float value)
{
	mAcceleration += mAccelerationRate * value * mDeltaTime;
	if (mAcceleration > mMaxAcceleration) {
		mAcceleration = mMaxAcceleration;
	}
}
void ACar::Deccelerate(float value)
{
	mAcceleration -= value * mDeltaTime;
	if (mAcceleration < mMinAcceleration) {
		mAcceleration = mMinAcceleration;
	}
}
//void ACar::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//}

