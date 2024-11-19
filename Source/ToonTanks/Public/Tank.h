// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"

#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category = "CameraComponent")
	class USpringArmComponent *SpringArm;

	UPROPERTY(EditAnywhere, Category = "CameraComponent")
	class UCameraComponent *Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void Move(float value);
	void Turn(float value);

	//mesh ��Ʈ��(GetHitResultUnderCursor)�� ���� reference �������� 
	APlayerController* PlayerControllerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed = 800.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float TurnRate = 90.0f;

	float Value;
};
