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

	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 600.0f;
	Value = 0;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	//����� APlayerController�� ������ �̱� ������ �ּҷ� �ʱ�ȭ ����ߵ�
	//�ٵ� GetController()�� AController �̱� ������ �θ� Ŭ������ �ּ� ������ ��������
	// ���� Acontroller �� �ٿ�ĳ���� ����ߵ� ������ 
	//Cast<��ȯŬ����>(Pointer)
	PlayerControllerRef = Cast<APlayerController>(GetController());


}


// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//��� �����ʹ� �ʱ�ȭ�� ����ϱ��� if(Pointer) �������� ��ȯ���� null ���� true ���� Ȯ���ؾ� ��
	//���� Ʈ���̽� �� ��Ʈ �̺�Ʈ�� ����� �������� ���� ���� 
	if(PlayerControllerRef){
		//��Ʈ�̺�Ʈ�� ����� �������� ���� ���� �������̶� ����� ���� ��ȯ ������ �ٸ� ex)HitResult.Actor , HitResult.ImpactPoint
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);

		//DrawDebugHelpers �� ����ױ�ü ���̺귯�� ������ ��� 
		DrawDebugSphere(GetWorld(),
		HitResult.ImpactPoint,
		25.0f,
		12,
		FColor::Blue,
		false,
		-1.0f);
		//basePawn ���� (�θ� Ŭ����) ������ �Լ��� �̿��Ͽ� ��ü ȸ�� 
		RotateTurret(HitResult.ImpactPoint);
		}
	
}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float value)
{
	// �ڷ� ���� ���ؼ� Move�� �ڷ� ������ value�� �����ؾߵ�
	this->Value = value;
	FVector DeltaLocation = FVector::ZeroVector;
	// x = value * deltatime * speed
	DeltaLocation.X = value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation,true);
}

void ATank::Turn(float value)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	// �ڷ� ����
	if (Value == -1)
	{
		// �ݴ� ����
		//  Yaw = value * Deltatime * speed
		DeltaRotator.Yaw = -1 * value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(DeltaRotator);
	}
	// ������ ����
	//  ������
	else
	{
		DeltaRotator.Yaw = value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(DeltaRotator);
	}
}
