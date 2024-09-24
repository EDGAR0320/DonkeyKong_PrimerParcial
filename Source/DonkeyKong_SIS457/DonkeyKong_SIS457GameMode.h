// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKong_SIS457GameMode.generated.h"

class APlataforma;
class ABarril;
class AConoDisparador;

UCLASS(minimalapi)
class ADonkeyKong_SIS457GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKong_SIS457GameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	//Plataforma 
	TArray <AActor*> PlataformasMap;
	APlataforma* TP;
	FVector Posicion;
	FRotator Rotacion;
	float Signo;
	float Tiempo;
	AActor* Destruir = nullptr;

	TArray<APlataforma*> PlataformasMoviles;

//	//Movimiento Aleatorio 
//	bool bPlataformasConMovimiento[5];//Para marcar la platafroma tiene movimiento o no
//
//	/*TArray<AActor* >Barriles;
//	AActor* Destruir;*/

private:
	// Referencia al Cono Disparador
	AConoDisparador* ConoDisparador;
};



