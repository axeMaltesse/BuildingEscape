// Copyright Lukasz Wrzolek (axeMaltesse)

#include "BuildingEscape.h"
#include "OpeningDoor.h"


// Sets default values for this component's properties
UOpeningDoor::UOpeningDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpeningDoor::BeginPlay()
{
	Super::BeginPlay();

	//Owner
	Owner = GetOwner();
}

void UOpeningDoor::OpenDoor() {
	//Changing the position
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.f));
}

void UOpeningDoor::CloseDoor() {
	//Changing the position
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.f));
}


// Called every frame
void UOpeningDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (GetTotalMassOfActorsOnPlate() > 50.f) { //TODO change 50 to a editable variable 
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds()-LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}
}

float UOpeningDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;
	
	//prevent the nullptr to get used
	if (!PressurePlate) { 
		UE_LOG(LogTemp, Error, TEXT("Pressure plate is not assigned! Item %s"), *GetOwner()->GetName());
		return 0; 
	}

	TArray<AActor*> OverlappingActors;
	//find all the overlaping actors
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	//iterate to add each mass of the actor
	for (auto& Iterator : OverlappingActors) {
		UE_LOG(LogTemp,Warning,TEXT("Actor name is %s"), *Iterator->GetName());
		TotalMass += Iterator->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass;
}

