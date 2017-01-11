// Copyright Lukasz Wrzolek (axeMaltesse)

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void FindPhysicsHandleComponent();
	void SetupInputComponent();

	//return hit for first physics in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//calculate the reach line starts
	const FVector GetReachLineStart();

	//calculate the reach line of the beam
	const FVector GetReachLineEnd();

private:

	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	///raycast and grab
	void Grab();

	///raycas and release
	void Release();

};
