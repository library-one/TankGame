// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Enemy.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API AEnemy : public ABasePawn
{
	GENERATED_BODY()

	AEnemy();

public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	// ��ũ�� Ŭ������ ������ �����ͷ� ��� (Ŭ���� ���漱��)
	class ATank *Tank;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true),Category="Attack")
	float FireRange= 300.f;

	//�߻�ü ������ TimerManager�� �� ���ڵ�
	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;
	void CheckFireCondition();

	bool InFireRange();
};
 