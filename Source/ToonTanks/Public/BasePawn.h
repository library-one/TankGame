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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

//�� Ŭ���������� ��� �� �� �ִ� ���� ������ struct �� �⺻�� public class �� �⺻�� private �̴� .
private:
	//UPROPERTY() �Ӽ��� VisibleAnywhere �� ������Ƽ�� ���ǵ����� detail�гο����� �� �� �ִ�.
	//EditAnywhere �� detail �гο��� �� �� �ְ� ������Ƽ�� �ǵ� �� �ִ�.
	//VisibleInstaceOnly �� level �� bp �� �ְ� worldoutliner ���� bp detail �� �� �� �� �ִ� ������Ƽ�� �� �ǵ�

	//UPROPERTY() �� �𸮾� ��ũ�η� �������Ʈ ����, ������ �÷���(�޸� ����)�� ��� �����ϱ� ������ ���� �ؾ���  
	UPROPERTY()
	class UCapsuleComponent* CapsuleComp;
	//�������μ������ �κп��� ���̺귯�� ��� ������ ������ �� �� �������� ������ ����� �κи� �������°� ����
	//#include "Components/CapsuleComponent.h"
	//�𸮾� ������ ���� �����̶�� ����� �մµ� �� ���Ͽ� ����� �����ö� ������ �ٿ��� �������� ��� ��� �δ��� �����ִ� ��� 
	//�տ� class �� �ٿ��ָ�� �� ����ҷ��� Ŭ���� ���� ���� ��� Ŭ������ ����� �ʼ� �̴�.
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(EditAnywhere)
	USceneComponent* AttackSpawnPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	float MovingSpeed;
};
