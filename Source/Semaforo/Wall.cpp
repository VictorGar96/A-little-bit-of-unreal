// Fill out your copyright notice in the Description page of Project Settings.

#include "Wall.h"


// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Crea el componente collider
	boxCollider = CreateDefaultSubobject<UBoxComponent>("Collider");

	//Modifica el tamaño del collider
	boxCollider->SetBoxExtent(FVector(50, 50, 50));

	//Establece la raíz de la jerarquía de componentes
	SetRootComponent(boxCollider);

	//Crea el componente collider
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	//Modifica la jerarquía de componentes
	mesh->AttachToComponent(boxCollider, FAttachmentTransformRules::SnapToTargetIncludingScale);

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	//Suscripción a los eventos trigger enter
	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &AWall::OnOverlapBegin);

	//Suscripción a los eventos trigger exit
	boxCollider->OnComponentEndOverlap.AddDynamic(this, &AWall::OnOverlapEnd);
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWall::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, 
						UPrimitiveComponent * OtherComponent, int32 OterBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor != nullptr && (OtherActor != this) && OtherComponent != nullptr)
	{
		cubeInstance = Cast<AMovableCube>(OtherActor);

		if (cubeInstance != nullptr)
			cubeInstance->Reverse();
	}
}

void AWall::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

