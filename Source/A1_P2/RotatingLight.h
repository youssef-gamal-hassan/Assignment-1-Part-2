// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingLight.generated.h"

UCLASS()
class A1_P2_API ARotatingLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingLight();
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* lightMesh;
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* OverlapBox;
	UPROPERTY(VisibleAnywhere)
		class USpotLightComponent* light;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void BeginOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
			bool bFromSweep, const FHitResult& SweepResult
		);	
	UFUNCTION()
		void EndOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex
		);

};
