// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "Tank.h"

#include "TankPlayerController.generated.h"


using namespace UP;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;	
private:
	void AimTowordCrosshair();
	bool GetSightRayHitLocation(FVector& _HitLocation) const;

	bool GetLookDirection(FVector2D _ScrLoc, FVector& _LookDir) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



public:
	virtual void Tick(float DeltaSeconds) override;
	
	
protected:
	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere)
		float CrossHairX = 0.5f;


	UPROPERTY(EditAnywhere)
		float CrossHairY = 0.333f;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;




};
