// Fill out your copyright notice in the Description page of Project Settings.

#include "LightOF.h"
#include "Engine.h"
#include "EngineUtils.h"

#include "DrawDebugHelpers.h" //Help us see the colliders


// Sets default values
ALightOF::ALightOF()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/// Intendidad de luz
	lightIntensity = 3000.f;

	pointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("pointLight"));
	pointLight->Intensity = lightIntensity;
	pointLight->bVisible = true;
	RootComponent = pointLight;

	/// Damos valor a las propiedades que va a tener la bombilla
	lightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	lightSphere->InitSphereRadius(300.0f);
	lightSphere->SetCollisionProfileName(TEXT("Trigger"));
	lightSphere->SetupAttachment(RootComponent);

	/// Suscribción al evento
	lightSphere->OnComponentBeginOverlap.AddDynamic(this, &ALightOF::OnOverlapBegin);
	lightSphere->OnComponentEndOverlap.AddDynamic(this, &ALightOF::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ALightOF::BeginPlay()
{
	Super::BeginPlay();
	//ToggleLight(true);

	//isCollisioning = false;

	///Colores del semáforo
	reddd = FLinearColor(255.f, 0.f, 0.f);
	greeen = FLinearColor(0.f, 255.f, 0.f);
}
	
// Called every frame
void ALightOF::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ToggleLight(true);

	/// Comprobamos si está colisionando
	if (isCollisioning)
	{
		/// Cambiamos el color a verde
		ChangeColor(reddd);

		for (int32 i = 0; i < cubos.Num(); ++i)
		{
			if (i == 0)
				cubos[i]->Displace();

			if(i != 0)
			{
				cubos[i]->Stop();
			}
		}
	}
	/// Comprobamos que la lista está vacía
	if (cubos.Num() == 0)
	{
		isCollisioning = false;
		/// Cambiamos el color a rojo
		ChangeColor(greeen);

	}

		
}

void ALightOF::ToggleLight(bool status)
{
	pointLight->ToggleVisibility(status);
}

void ALightOF::ChangeColor(struct FLinearColor color)
{
	pointLight->SetLightColor(color, true);
}

void ALightOF::addToList()
{
}

void ALightOF::elimFromList()
{
}

void ALightOF::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, 
							  UPrimitiveComponent * OtherComponent, int32 OterBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	isCollisioning = true;

	///Compruebo si con aquello con lo que ha colisionado es una instancia del cubo
	if (OtherActor != nullptr && (OtherActor != this) && OtherComponent != nullptr)
	{
		AcubeInstance = Cast<AMovableCube>(OtherActor);

		if (AcubeInstance != nullptr)
		{
			/// Si esta instancia del cubo no está dentro del Array la añado 
			if (!cubos.Contains(AcubeInstance))
			{
				cubos.Add(AcubeInstance);
				UE_LOG(LogTemp, Warning, TEXT("Adding"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Removing"));
			}
		}
	}
}

void ALightOF::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor != nullptr && (OtherActor != this) && OtherComp != nullptr)
	{
		AcubeInstance = Cast<AMovableCube>(OtherActor);

		if (AcubeInstance != nullptr)
		{
		if(cubos.Num() > 0)
			cubos.Remove(AcubeInstance);			
		}
	}
}

