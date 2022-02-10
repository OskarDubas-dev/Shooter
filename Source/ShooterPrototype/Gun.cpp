// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include <concrt.h>

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "ToolContextInterfaces.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh,TEXT("MuzzleFlashSocket"));
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return;
	AController* OwnerController = OwnerPawn->GetController();

	FVector OwnerLocation;
	FRotator OwnerRotation;
	OwnerController->GetPlayerViewPoint(OwnerLocation, OwnerRotation);
	//DrawDebugCamera(GetWorld(), OwnerLocation, OwnerRotation, 90.0, 1.0, FColor::Red, true );


	FVector End = OwnerLocation + OwnerRotation.Vector() * MaxRange;
	// TODO: line trace
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, OwnerLocation, End,
	                                                     ECollisionChannel::ECC_GameTraceChannel1, Params);
	if (bSuccess)
	{
		FVector ShotDirection = -OwnerRotation.Vector();
		//DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		
		AActor* HitActor = Hit.GetActor();
		if(HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
		
	}
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
