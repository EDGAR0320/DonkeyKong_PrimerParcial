// Fill out your copyright notice in the Description page of Project Settings.


#include "ConoDisparador.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Projectile.h" // Asumiendo que tienes una clase Projectil o similar
// Sets default values
AConoDisparador::AConoDisparador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear la malla del cono
	ConoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConoMesh"));
	RootComponent = ConoMesh;

	// Tiempo entre disparos
	TiempoEntreDisparos = 2.0f;

}

// Called when the game starts or when spawned
void AConoDisparador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConoDisparador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Llamar a la función de disparo en todas direcciones
	DispararEnTodasDirecciones();
}

void AConoDisparador::DispararEnTodasDirecciones()
{
	// Número de direcciones a disparar
	int32 NumDirecciones = 8; // Cambia este valor para más direcciones
	for (int32 i = 0; i < NumDirecciones; ++i)
	{
		// Calcular ángulo para cada dirección
		float Angle = (360.0f / NumDirecciones) * i;
		FRotator DisparoRotacion = FRotator(0, Angle, 0);

		// Posición y rotación para el proyectil
		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = DisparoRotacion;

		// Spawnear el proyectil (asumiendo que tienes una clase de proyectil)
		GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass(), SpawnLocation, SpawnRotation);
	}
}

