// Fill out your copyright notice in the Description page of Project Settings.


#include "Car.h"
#include "ObstacleComponent.h"
// Sets default values
ACar::ACar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();
	mMeshComp->OnComponentBeginOverlap.AddDynamic(this, &ACar::OnOverlapBegin);

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
void ACar::HitByObstacle(UObstacleComponent* obstacle)
{
	GEngine->AddOnScreenDebugMessage(14, 5, FColor::Orange, TEXT("Car : Hit by Obstacle"));
	mHealth -= 1;
	if (mHealth == 0) {
		GEngine->AddOnScreenDebugMessage(14, 5, FColor::Orange, TEXT("Car : Died"));
		return;
	}
	
	GEngine->AddOnScreenDebugMessage(15, 5, FColor::Orange, FString::Printf(TEXT("Car : Health : %d"), mHealth));
}
void ACar::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto obs = Cast<UObstacleComponent>(OtherActor->GetComponentByClass(UObstacleComponent::StaticClass()));
	if (!obs) {
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Orange, TEXT("Car : Hit"));
		return;
	}
	HitByObstacle(obs);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Hit by "+ OtherActor->GetName()));
}

