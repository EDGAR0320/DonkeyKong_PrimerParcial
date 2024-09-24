// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_SIS457GameMode.h"
#include "DonkeyKong_SIS457Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Plataforma.h"
#include "Barril.h"
#include "Asesino.h"
#include "Kismet/KismetMathLibrary.h" // Para generar números aleatorios
#include "MuroFragil.h"
#include "Engine/World.h"
#include "ConoDisparador.h"

ADonkeyKong_SIS457GameMode::ADonkeyKong_SIS457GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADonkeyKong_SIS457GameMode::BeginPlay()
{
	//ConoDisparador 
	// Posición y rotación donde queremos que aparezca el ConoDisparador
	FVector ConoPosition = FVector(500.f, 0.f, 300.f);
	FRotator ConoRotation = FRotator::ZeroRotator;

	// Generar el Cono Disparador
	ConoDisparador = GetWorld()->SpawnActor<AConoDisparador>(AConoDisparador::StaticClass(), ConoPosition, ConoRotation);
	
	
	//MuroFragil
	// Posición donde queremos spawnear el muro frágil
	FVector MuroPosition = FVector(500.f, 0.f, 300.f);
	FRotator MuroRotation = FRotator::ZeroRotator;

	// Generar el muro frágil
	GetWorld()->SpawnActor<AMuroFragil>(AMuroFragil::StaticClass(), MuroPosition, MuroRotation);

	//Plataforma
	Super::BeginPlay();
	Posicion = FVector(1206.8f, 1000.f, 180.f);
	Rotacion = FRotator(0.0f, 0.0f, 5.0f);
	Signo = 1.0f;
	Tiempo = 0.0f;

	// Generar plataformas
	/*for (int i = 0; i < 5; i++) {
		for (int y = 10; y >= 1; y--) {
			Posicion += FVector(0.0f, -250.f * Signo, 22.f);
			if (i != 4) {
				TP = GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, Rotacion);
			}
			else {
				Posicion.Z -= 22;
				TP = GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, FRotator::ZeroRotator);
			}
			PlataformasMap.Add(TP);
		}
		Signo *= -1.0f;
		Posicion += FVector(0.0f, -100.f * Signo, 300.f);
		Rotacion.Roll *= -1;
	}*/

	// Seleccionar 3 plataformas aleatoriamente para movimiento aleatorio
	/*for (int32 i = 0; i < 3; i++) {
		int32 indexAleatorio = UKismetMathLibrary::RandomIntegerInRange(0, PlataformasMap.Num() - 1);
		APlataforma* PlataformaSeleccionada = Cast<APlataforma>(PlataformasMap[indexAleatorio]);
		if (PlataformaSeleccionada) {
			PlataformasMoviles.Add(PlataformaSeleccionada);
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Cantidad del contenedor: %d"), PlataformasMap.Num()));*/

	// Crear 5 plataformas
	for (int i = 0; i < 5; i++) {
		for (int y = 10; y >= 1; y--) {
			Posicion += FVector(0.0f, -250.f * Signo, 22.f);
			TP = GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, Rotacion);
			PlataformasMap.Add(TP);
		}
		Signo *= -1.0f;
		Posicion += FVector(0.0f, -100.f * Signo, 300.f);
		Rotacion.Roll *= -1;
	}

	// Seleccionar 2 plataformas aleatoriamente para movimiento aleatorio
	TArray<int32> IndicesAleatorios;
	while (IndicesAleatorios.Num() < 2) {
		int32 indexAleatorio = UKismetMathLibrary::RandomIntegerInRange(0, PlataformasMap.Num() - 1);
		if (!IndicesAleatorios.Contains(indexAleatorio)) {
			IndicesAleatorios.Add(indexAleatorio);
			APlataforma* PlataformaSeleccionada = Cast<APlataforma>(PlataformasMap[indexAleatorio]);
			if (PlataformaSeleccionada) {
				PlataformasMoviles.Add(PlataformaSeleccionada);
			}
		}
	}

	// Hacer desaparecer una de las divisiones de las plataformas seleccionadas
	for (APlataforma* PlataformaMovil : PlataformasMoviles) {
		if (PlataformaMovil) {
			PlataformaMovil->EliminarDivisionIzquierdaADerecha();
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Cantidad del contenedor: %d"), PlataformasMap.Num()));


}


void ADonkeyKong_SIS457GameMode::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	Tiempo += DeltaTime;

	// Aplicar movimiento a las plataformas seleccionadas
	for (APlataforma* PlataformaMovil : PlataformasMoviles) {
		if (PlataformaMovil) {
			PlataformaMovil->MovimientoAleatorio();
		}
	}
}

