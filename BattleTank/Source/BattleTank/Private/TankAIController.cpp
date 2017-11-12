// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)	
		return nullptr;
	
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	auto MyTank = GetControlledTank();

	if(!MyTank)
		UE_LOG(LogTemp, Error, TEXT("Miss Controlled Tank."));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Miss Player Tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank."));
	}

	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//..
	auto MyTank = GetControlledTank();	
	
	MyTank->AimAt(GetPlayerTank()->GetActorLocation());
}
