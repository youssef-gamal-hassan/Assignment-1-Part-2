// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingMaterial.generated.h"

UCLASS()
class A1_P2_API ARotatingMaterial : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingMaterial();
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* ObjectMesh;
	UPROPERTY(EditAnywhere)
		class UMaterial* Material1;

	UPROPERTY(EditAnywhere)
		class UMaterial* Material2;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 numRotations;

};
