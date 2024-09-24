// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroFragil.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "DonkeyKong_SIS457Character.h"

// Sets default values
AMuroFragil::AMuroFragil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear el componente de malla y establecer como root
	MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	RootComponent = MuroMesh;

	// Configurar la colisión
	MuroMesh->SetSimulatePhysics(true);
	MuroMesh->SetNotifyRigidBodyCollision(true);
	MuroMesh->BodyInstance.SetCollisionProfileName("BlockAllDynamic");

	// Vincular la función de colisión
	MuroMesh->OnComponentHit.AddDynamic(this, &AMuroFragil::OnMuroHit);

}

// Called when the game starts or when spawned
void AMuroFragil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuroFragil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMuroFragil::OnMuroHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Verificar si el actor que colisiona es el personaje
	if (OtherActor && OtherActor->IsA(ADonkeyKong_SIS457Character::StaticClass()))
	{
		// Destruir el muro
		Destroy();
	}
}

