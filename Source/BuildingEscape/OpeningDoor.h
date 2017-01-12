// Copyright Lukasz Wrzolek (axeMaltesse)

#pragma once

#include "Components/ActorComponent.h"
#include "OpeningDoor.generated.h"
//declaration of function to talk to the blueprint
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpeningDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpeningDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Property to talk to the blueprint
	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnCloseRequest;

private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate = nullptr;


	AActor *Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();

	UPROPERTY(EditAnywhere)
		float TriggerMass = 50.f;
};
