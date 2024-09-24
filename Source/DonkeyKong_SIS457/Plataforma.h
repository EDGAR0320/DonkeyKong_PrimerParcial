// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

UCLASS()
class DONKEYKONG_SIS457_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere)

	//Declaracion de un puntero a un componente malla
	UStaticMeshComponent* plataforma;
	TArray<APlataforma*> PlataformasMoviles;
	//TArray<UStaticMeshComponent*> Subdivisiones;

protected:
	FVector PosicionInicial;
	FVector PosicionActual;
	FVector PosicionFinal;
	float IncrementoY;
	float IncrementoX;
	bool moverseY;
	bool moverseX;
	float T;


public:
	
		void MovimientoY();
		void MovimientoX();
		void MovimientoAleatorio();
		void EliminarDivisionIzquierdaADerecha(); // Nuevo método para eliminar una división

};
