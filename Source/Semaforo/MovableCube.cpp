// Fill out your copyright notice in the Description page of Project Settings.

#include "MovableCube.h"
#include "Engine.h"
#include "EngineUtils.h"
#include "DrawDebugHelpers.h" //Help us see the colliders

// Sets default values
AMovableCube::AMovableCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/// Creamos la malla del objeto y se la asignamos a RootComponent
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Malla del Objecto");
	RootComponent = mesh;
	
	/// Creamos el colisionador, le asignamos un tamaño y lo attachamos al RootComponent
	collider = CreateDefaultSubobject<UBoxComponent>("Colisionador");
	collider->SetBoxExtent(FVector(120, 120, 120));
	collider->AttachTo(RootComponent);

	triggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	triggerCapsule->InitCapsuleSize(20, 20);
	triggerCapsule->SetupAttachment(RootComponent);

	/*triggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AMovableCube::OnOverlapBegin);
	triggerCapsule->OnComponentEndOverlap.AddDynamic  (this, &AMovableCube::OnOverlapEnd  );
	*/
}

// Called when the game starts or when spawned
void AMovableCube::BeginPlay()
{
	Super::BeginPlay();
	Displace();
}

// Called every frame
void AMovableCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ableToMove)
	{
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * DeltaTime * speed);
	}

}

void AMovableCube::Displace()
{
	ableToMove = true;
}

void AMovableCube::Stop()
{
	ableToMove = false;
}

void AMovableCube::Reverse()
{
	speed = -speed;
}

//void AMovableCube::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int32 OterBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//
//	if (OtherActor && (OtherActor != this) && OverlappedComponent)
//	{
//		lightInstance = Cast<ALightOF>(OtherActor);
//
//		if (lightInstance != nullptr)
//		{
//			speed = -speed;
//		}
//	}
//}
//
//void AMovableCube::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
//{
//
//}

