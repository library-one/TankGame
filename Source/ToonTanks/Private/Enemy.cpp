// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Tank.h"
#include "kismet/GameplayStatics.h"
#include "TimerManager.h"
AEnemy::AEnemy()
{
}

void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (InFireRange())
    {
        // 만약 사정거리에 있다면 적이 탱크를 향해 돌림
        RotateTurret(Tank->GetActorLocation());
    }
}
void AEnemy::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    // 헤더 TimerManager를 가져와 SetTimer함수를 이용해 인자를 넣어 설정 함
    // 1. TimerHandle 인자값
    // 2. 클래스 자기자신 호출
    // 3. 호출 조건 함수
    // 4. 호출 시간
    // 5. 반복
    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemy::CheckFireCondition, FireRate, true);
}

// 콜백 함수
void AEnemy::CheckFireCondition()
{
    if (InFireRange())
    {
        Fire();
    }
}

bool AEnemy::InFireRange()
{
    if (Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        // 탱크의 거리가 사정거리 안에 있는지 확인
        if (Distance <= FireRange)
        {
            return true;
        }
    }
    return false;
}
