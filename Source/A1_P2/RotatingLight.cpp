// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingLight.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SpotLightComponent.h"

// Sets default values
ARotatingLight::ARotatingLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	lightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightMesh"));
	SetRootComponent(lightMesh);

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	OverlapBox->SetupAttachment(GetRootComponent());

	light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	light->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ARotatingLight::BeginPlay()
{
	Super::BeginPlay();

	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ARotatingLight::BeginOverlap);
	OverlapBox->OnComponentEndOverlap.AddDynamic(this, &ARotatingLight::EndOverlap);	
}

// Called every frame
void ARotatingLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += 30.f * DeltaTime;
	SetActorRotation(NewRotation);

}

void ARotatingLight::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	light->ToggleVisibility();
}

void ARotatingLight::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	light->ToggleVisibility();
}

