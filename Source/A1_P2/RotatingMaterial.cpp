// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingMaterial.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ARotatingMaterial::ARotatingMaterial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightMesh"));
	SetRootComponent(ObjectMesh);	
	Material1 = CreateDefaultSubobject<UMaterial>(TEXT("Material1"));
	Material2 = CreateDefaultSubobject<UMaterial>(TEXT("Material2"));
	numRotations = 0;
}

// Called when the game starts or when spawned
void ARotatingMaterial::BeginPlay()
{
	Super::BeginPlay();
	ObjectMesh->SetMaterial(0, Material1);
	numRotations = 1;
}

// Called every frame
void ARotatingMaterial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator rotate = GetActorRotation();
	rotate.Yaw += 150.f * DeltaTime;
	SetActorRotation(rotate);

	if (rotate.Yaw >= 180.f)
	{
		numRotations++;
		rotate.Yaw = -180.f;
	}
	if (numRotations % 10 == 0)
	{
		if (ObjectMesh->GetMaterial(0) == Material1) {
			ObjectMesh->SetMaterial(0, Material2);

		}
		else
		{
			ObjectMesh->SetMaterial(0, Material1);

		}
		numRotations++;
		
	}
	if (numRotations > 100000) {
		numRotations = 0;
	}
}

