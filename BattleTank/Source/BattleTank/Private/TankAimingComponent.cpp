// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrelMesh(UStaticMeshComponent* _BarrelMesh)
{
	BarrelMesh = _BarrelMesh;
}

FVector UTankAimingComponent::GetAimingLocation()
{
	return AimLocation;
}


void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{

	//TODO : Aim At WorldSpaceAim is Target Position and Launchspeed is Projectile Speed..

	
	if (!BarrelMesh)
		return;

	FVector OutLaunchVelocity;//
	FVector StartLocation = BarrelMesh->GetSocketLocation(FName("Projectile"));



	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT OutLaunchVelocity,
		StartLocation,
		WorldSpaceAim,
		LaunchSpeed,
		true,
		0,
		0,
		ESuggestProjVelocityTraceOption::OnlyTraceWhileAscending,
		FCollisionResponseParams::DefaultResponseParam,TArray<AActor*>(),
		true))
	{

		//Calculate the OutLaunchVelocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("Suggest Aim at %s"), * AimDirection.ToString());


	}





	
	AimLocation = WorldSpaceAim;

}

