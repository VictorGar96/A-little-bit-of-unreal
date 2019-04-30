// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "MovableCube.h"
#include "Wall.generated.h"

UCLASS()
class SEMAFORO_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	

	AMovableCube* cubeInstance;

	//Colisionador del objeto
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
		class UBoxComponent* boxCollider;

	//Malla del objeto
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UStaticMeshComponent* mesh;

	// Sets default values for this actor's properties
	AWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OterBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	
	
};
