// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(CapsuleComp);

	AttackSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	AttackSpawnPoint->SetupAttachment(TurretMesh);

}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	//FVector �� �� ����Ű�� ���� ��ǥ���� ���� Ʈ���̽��� HitResult ������ ������ ��ġ ���� ���� ��ǥ���� ����
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	//ToTarget �� ��ǥ�� ��ŭ Pitch , Yaw , Roll �� ȸ������ �༭ �� ȸ������ ������ Rotator�� ������ ȸ���� ���� ����ü�� 
	//�ٴڰ� �����ϰ� ȸ�� ��Ű�� �������� Pitch ���� Roll ���� 0���� ���� ȸ������ Yaw ���� ���� 
	FRotator LookAtRotation = FRotator(0.f,ToTarget.Rotation().Yaw,0.f);

	//ȸ�� ���� �Ҵ� �Ҷ� ���彺���̽��� ��ǥ������ ������ ��ǥ���� �� ���� �����Ͽ� ȸ�� ��Ű�� ������
	//LocalOffset�� �ƴ� WorldRotation ���� ���� �־��ִ°� ���� ���͸� �������� ���彺���̽��� ��ǥ�� �̵���Ű�� �����̴�.
	//RInterTo ���� �Լ��� �����? ȸ���� �� �ε巴�� ����
	TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(),LookAtRotation,
								UGameplayStatics::GetWorldDeltaSeconds(this),5.f));
}

void ABasePawn::Fire()
{
	FVector ProjectileSpawnPointLocation = AttackSpawnPoint->GetComponentLocation();
		DrawDebugSphere(GetWorld(),
						ProjectileSpawnPointLocation,
						25.0f,
						12,
						FColor::Red,
						false,
						3.f);
}