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
        // ���� �����Ÿ��� �ִٸ� ���� ��ũ�� ���� ����
        RotateTurret(Tank->GetActorLocation());
    }
}
void AEnemy::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    // ��� TimerManager�� ������ SetTimer�Լ��� �̿��� ���ڸ� �־� ���� ��
    // 1. TimerHandle ���ڰ�
    // 2. Ŭ���� �ڱ��ڽ� ȣ��
    // 3. ȣ�� ���� �Լ�
    // 4. ȣ�� �ð�
    // 5. �ݺ�
    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemy::CheckFireCondition, FireRate, true);
}

// �ݹ� �Լ�
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
        // ��ũ�� �Ÿ��� �����Ÿ� �ȿ� �ִ��� Ȯ��
        if (Distance <= FireRange)
        {
            return true;
        }
    }
    return false;
}
