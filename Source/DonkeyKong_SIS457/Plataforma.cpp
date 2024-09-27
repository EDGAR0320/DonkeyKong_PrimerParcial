// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//establece el componenete raiz de la malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> plataformaMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer'"));
	// Crear el componente de malla estática
	plataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("plataforma"));
	//SetStaticMesh() asigna una malla estatica a la instancia
	//CubeMeshAsset.Object obtiene el objeto malla y lo asigna a la instancia
	plataforma->SetStaticMesh(plataformaMesh.Object);
	// Establecer el componente de malla como el componente raíz
	SetRootComponent(plataforma);
	//Habitar fisicas de  la instancia
	//plataforma->SetSimulatePhysics(false);
	//Modifica la forma del objeto
	plataforma->SetWorldScale3D(FVector(1.0f, 3.0f, 0.5f));
	//Cambia el angulo del objeto (y,z,x)
	//plataforma->SetRelativeRotation(FRotator(0.0f, 0.0f, 5.0f));
	//Hacer invisible el objeto
	plataforma->SetVisibility(true);

	IncrementoY = 2.0f;
	IncrementoX = 2.0f;
	moverseY = true;
	moverseX = true;
	T = 0.0f;

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
	PosicionInicial = GetActorLocation();
	PosicionActual = PosicionInicial;
	PosicionFinal = PosicionActual + FVector(0.0f, -840.0f, 0.0f);
	/*IncrementoY = 2.0f;
	moverse = true;
	T = 0.0f;*/
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovimientoAleatorio();

}

void APlataforma::MovimientoY()
{
	if (moverseY)
	{
		if (PosicionActual.Y > PosicionFinal.Y) PosicionActual.Y -= IncrementoY;
		else moverseY = false;
	}
	else
	{
		if (PosicionActual.Y < PosicionInicial.Y) PosicionActual.Y += IncrementoY;
		else moverseY = true;
	}

}

void APlataforma::MovimientoX()
{
	if (moverseX)
	{
		if (PosicionActual.X < PosicionInicial.X + 200.0f) PosicionActual.X += IncrementoX;
		else moverseX = false;
	}
	else
	{
		if (PosicionActual.X > PosicionInicial.X) PosicionActual.X -= IncrementoX;
		else moverseX = true;
	}
}

void APlataforma::MovimientoAleatorio()
{
	//if (PlataformasMoviles.Contains(this)) {
	//	// Aplica movimiento aleatorio solo si es una de las plataformas móviles
	//	MovimientoY();  // Movimiento en Y
	//	MovimientoX();  // Movimiento en X
	//}
	//SetActorLocation(PosicionActual); 

	MovimientoY();  // Movimiento en Y
	MovimientoX();  // Movimiento en X
	SetActorLocation(PosicionActual);
}