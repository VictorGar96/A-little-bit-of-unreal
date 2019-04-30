// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "LightOF.h"
#include "MovableCube.generated.h"

UCLASS()
class SEMAFORO_API AMovableCube : public AActor
{
	GENERATED_BODY()

public:	
///	ALightOF* lightInstance;

	UPROPERTY(EditAnywhere, Category = "velocidad")
		float speed;
	UPROPERTY(EditAnywhere, Category = "Malla")
		class UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, Category = "Colsionador")
		class UBoxComponent* collider;
	UPROPERTY(EditAnywhere, Category = "Trigger")
		class UCapsuleComponent* triggerCapsule;

	// Sets default values for this actor's properties
	AMovableCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void Displace();

	UFUNCTION()
		void Stop();

	UFUNCTION()
		void Reverse();

	/*UFUNCTION()
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
*/
private:
	bool ableToMove;

};
