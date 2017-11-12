// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;


public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void AimAt(FVector HitLocation);

private:
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelMesh(UStaticMeshComponent* _BarrelMesh);
	UFUNCTION(BlueprintPure, Category = "Aiming")
		FVector GetAimingLocation();
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000.0f;




	
};
