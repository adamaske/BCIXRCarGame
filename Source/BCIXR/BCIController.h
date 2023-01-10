// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BCIController.generated.h"

/**
 * 
 */
UCLASS()
class BCIXR_API ABCIController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void OnPossess(APawn* PawnToPossess) override;

	UFUNCTION(BlueprintCallable)
		void RecieveBCIInput(FString command, float value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ACar* mCar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ARoadManager> mRoadManagerBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ARoadManager* mRoadManager;

};
