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

//�� Ŭ���������� ���? �� �� �ִ� ���� ������ struct �� �⺻�� public class �� �⺻�� private �̴� .
private:
protected:
	//UPROPERTY() �Ӽ��� VisibleAnywhere �� ������Ƽ�� ���ǵ����� detail�гο����� �� �� �ִ�.
	//EditAnywhere �� detail �гο��� �� �� �ְ� ������Ƽ�� �ǵ� �� �ִ�.
	//VisibleInstaceOnly �� level �� bp �� �ְ� worldoutliner ���� bp detail �� �� �� �� �ִ� ������Ƽ�� �� �ǵ�

	//UPROPERTY() �� �𸮾� ��ũ�η� ��������Ʈ ����, ������ �÷���(�޸� ����)�� ���? �����ϱ� ������ ���� �ؾ���  
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category= "Components2",meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComp;
	//�������μ������? �κп��� ���̺귯�� ���? ������ ������ �� �� �������� ������ �����? �κи� �������°� ����
	//#include "Components/CapsuleComponent.h"
	//�𸮾� ������ ���� �����̶��? �����? �մµ� �� ���Ͽ� �����? �����ö� ������ �ٿ��� �������� ���? ���? �δ��� �����ִ� ���? 
	//�տ� class �� �ٿ��ָ��? �� ����ҷ���? Ŭ���� ���� ���� ���? Ŭ������ �����? �ʼ� �̴�.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	USceneComponent* AttackSpawnPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
};
