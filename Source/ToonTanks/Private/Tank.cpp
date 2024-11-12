// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));

	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength=600.0f;
	Speed =100.f;

}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &ATank::Move);
}

void ATank::Move(float value)
{
	FVector DeltaLocation=FVector::ZeroVector;
	float deltatime = UGameplayStatics::GetWorldDeltaSeconds(this);
	// x = value * deltatime * speed
	DeltaLocation.X=value*Speed *deltatime;
	AddActorLocalOffset(DeltaLocation);
}
