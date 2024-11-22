  // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:

	void RotateTurret(FVector LookAtTarget);
	void Fire();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category= "Components2",meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	USceneComponent* AttackSpawnPoint;

	//Ŭ���� Ÿ�� c++ ���� 
	UPROPERTY(EditAnywhere, Category ="Attack")
	TSubclassOf<class AProjectile> ProjectileClass;
};
