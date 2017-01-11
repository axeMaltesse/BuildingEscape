// Copyright Lukasz Wrzolek (axeMaltesse)

#pragma once

#include "Components/ActorComponent.h"
#include "OpeningDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpeningDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpeningDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;

private:
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate = nullptr;


	AActor *Owner = nullptr;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;

	float LastDoorOpenTime;

	float GetTotalMassOfActorsOnPlate();
};
