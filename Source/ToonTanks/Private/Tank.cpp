// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(TurretMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	SpringArm->bEnableCameraLag=true;
	SpringArm->CameraLagSpeed=3.0f;
	SpringArm->TargetArmLength = 600.0f;
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	// ????? APlayerController?? ?????? ??? ?????? ???? ???? ??????
	// ??? GetController()?? AController ??? ?????? ?��? ??????? ??? ?????? ????????
	//  ???? Acontroller ?? ???��???? ?????? ??????
	// Cast<????????>(Pointer)
	PlayerControllerRef = Cast<APlayerController>(GetController());
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// ??? ??????? ?????? ???????? if(Pointer) ???????? ??????? null ???? true ???? ?????? ??
	// ???? ?????? ?? ??? ?????? ????? ???????? ???? ????
	if (PlayerControllerRef)
	{
		// ????????? ????? ???????? ???? ???? ????????? ????? ???? ??? ?????? ??? ex)HitResult.Actor , HitResult.ImpactPoint
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

		// DrawDebugHelpers ?? ??????? ??????? ?????? ???
		DrawDebugSphere(GetWorld(),
						HitResult.ImpactPoint,
						25.0f,
						12,
						FColor::Blue,
						false,
						-1.0f);
		// basePawn ???? (?��? ?????) ?????? ????? ?????? ??? ???
		RotateTurret(HitResult.ImpactPoint);
	}
}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"),IE_Pressed,this, &ATank::Fire);
}

void ATank::Move(float value)
{
	// ??? ???? ????? Move?? ??? ?????? value?? ????????
	this->Value = value;
	FVector DeltaLocation = FVector::ZeroVector;
	// x = value * deltatime * speed
	DeltaLocation.X = value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float value)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	// ??? ????
	if (Value == -1)
	{
		// ??? ????
		//  Yaw = value * Deltatime * speed
		DeltaRotator.Yaw = -1 * value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(DeltaRotator);
	}
	// ?????? ????
	//  ??????
	else
	{
		DeltaRotator.Yaw = value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(DeltaRotator);
	}
}
