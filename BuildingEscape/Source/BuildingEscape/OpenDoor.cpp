// Copyright Justin Guarino 2017

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	//Find owning actor
	AActor* Owner = GetOwner();
	//Create new rotation for door
	FRotator* NewRotation = new FRotator(0.f, -90.f, 0.f);
	//Set the new door rotation
	Owner->SetActorRotation(*NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//if actor in volume, open door
		OpenDoor();
	}
}

