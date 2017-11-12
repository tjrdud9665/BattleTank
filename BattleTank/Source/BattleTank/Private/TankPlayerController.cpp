// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"



void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	

	AimTowordCrosshair();


	
	
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto PossessedTank = GetControlledTank();

	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller is not Possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller Found : %s"),*PossessedTank->GetName());
	}

	

}


bool ATankPlayerController::GetSightRayHitLocation(FVector& _HitLocation) const
{
	//TODO : CrossHair's Location to LineTrace 


	int32 ViewportX, ViewportY;
	GetViewportSize(OUT ViewportX, OUT ViewportY);

	// CrossHair's Location..
	auto ScreenLocation = FVector2D(ViewportX * CrossHairX, ViewportY * CrossHairY);


	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, _HitLocation);
	}


	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D _ScrLoc, FVector& _LookDir) const
{
	FVector CameraWorldLocation;	

	return DeprojectScreenPositionToWorld(
		_ScrLoc.X,
		_ScrLoc.Y,
		OUT CameraWorldLocation,
		OUT _LookDir
	);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const 
{
	FHitResult HitResult;

	auto StartLocation = PlayerCameraManager->GetCameraLocation();

	auto EndLocation = StartLocation + (LookDirection *LineTraceRange);	

	
	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;

	}
	return false;

}
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowordCrosshair()
{
	auto ControlTank = GetControlledTank();

	if (!ControlTank)
		return;


	FVector HitLocation;
	GetSightRayHitLocation(OUT HitLocation);

	//ControlTank->AimAt(HitLocation);

		

	
}
