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
        // 탱크의 거리 구하기
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        // 탱크의 거리가 사정거리 안에 있는지 확인
        if (Distance <= FireRange)
        {
            // 만약 사정거리에 있다면 적이 탱크를 향해 돌림
            RotateTurret(Tank->GetActorLocation());
        }
    }
}
void AEnemy::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}