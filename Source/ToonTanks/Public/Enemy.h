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
	// 탱크의 클래스를 가져와 포인터로 사용 (클래스 전방선언)
	class ATank *Tank;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true),Category="Attack")
	float FireRange= 300.f;

	//발사체 딜레이 TimerManager에 쓸 인자들
	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;
	void CheckFireCondition();

	bool InFireRange();
};
 