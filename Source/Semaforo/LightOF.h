// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Color.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Array.h"
#include "MovableCube.h"
#include "LightOF.generated.h"

UCLASS()
class SEMAFORO_API ALightOF : public AActor
{
	GENERATED_BODY()

public:	

	class AMovableCube* AcubeInstance;

	TArray<AMovableCube*> cubos;

	UPROPERTY(EditAnywhere, Category = "Colisionador")
		class UBoxComponent* collider;
	
	/// Definición de los parámetros de la bombilla
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class UPointLightComponent* pointLight;
	UPROPERTY(VisibleAnywhere, Category = "Light Sphere")
		class USphereComponent* lightSphere;
	UPROPERTY(VisibleAnywhere, Category = "Light Intensity")
		float lightIntensity;


	struct FLinearColor reddd;
	struct FLinearColor greeen;

	bool light_status;
	bool isCollisioning;

	// Sets default values for this actor's properties
	ALightOF();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void ToggleLight(bool status);

	UFUNCTION()
		void ChangeColor(struct FLinearColor color);

	UFUNCTION()
		void addToList();

	UFUNCTION()
		void elimFromList();


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
