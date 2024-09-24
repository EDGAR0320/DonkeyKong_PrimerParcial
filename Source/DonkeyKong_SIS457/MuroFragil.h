// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MuroFragil.generated.h"

UCLASS()
class DONKEYKONG_SIS457_API AMuroFragil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMuroFragil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Componente para la malla
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* MuroMesh;

	// Función para manejar la colisión
	UFUNCTION()
	void OnMuroHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
