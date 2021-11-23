// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class UNREALGAMECOURSE_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float TargetPitch;

	//it has '_Implementation' added because we specified in the interface header
	//that it is a BlueprintNativeEvent
	void Interact_Implementation(APawn* InstigatorPawn) override;
	
protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ASItemChest();
};
