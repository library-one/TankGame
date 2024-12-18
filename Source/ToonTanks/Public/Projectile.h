// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditDefaultsOnly,Category="Mesh")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess="true"),Category="Movement")
	class UProjectileMovementComponent* ProjectileMovement;

	//델리게이트 함수 바인딩 콜백함수가 적용될려면 UFUNCTION()이 있어야 한다.
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit);
};
