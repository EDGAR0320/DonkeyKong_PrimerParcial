// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConoDisparador.generated.h"

UCLASS()
class DONKEYKONG_SIS457_API AConoDisparador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConoDisparador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Malla del Cono
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ConoMesh;

	// Tiempo entre disparos
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Disparo", meta = (AllowPrivateAccess = "true"))
	float TiempoEntreDisparos;

	// Función para disparar en todas direcciones
	void DispararEnTodasDirecciones();
};
