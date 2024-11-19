// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Tank.h"
#include "kismet/GameplayStatics.h"

AEnemy::AEnemy()
{
}

void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Tank)
    {
        // ��ũ�� �Ÿ� ���ϱ�
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        // ��ũ�� �Ÿ��� �����Ÿ� �ȿ� �ִ��� Ȯ��
        if (Distance <= FireRange)
        {
            // ���� �����Ÿ��� �ִٸ� ���� ��ũ�� ���� ����
            RotateTurret(Tank->GetActorLocation());
        }
    }
}
void AEnemy::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}