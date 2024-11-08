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

//이 클래스에서만 사용 할 수 있는 접근 지정자 struct 는 기본이 public class 는 기본이 private 이다 .
private:
protected:
	//UPROPERTY() 속성중 VisibleAnywhere 은 프로퍼티는 못건들지만 detail패널에서는 볼 수 있다.
	//EditAnywhere 은 detail 패널에서 볼 수 있고 프로퍼티도 건들 수 있다.
	//VisibleInstaceOnly 는 level 에 bp 를 넣고 worldoutliner 에서 bp detail 에 서 볼 수 있다 프로퍼티는 못 건듦

	//UPROPERTY() 는 언리얼 메크로로 블루프린트 적용, 가비지 컬렉션(메모리 관리)를 사용 가능하기 때문에 적용 해야함  
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category= "Components2",meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComp;
	//프리프로세서라는 부분에서 라이브러리 헤더 파일을 가져올 때 다 가져오기 때문에 사용할 부분만 가져오는게 맞음
	//#include "Components/CapsuleComponent.h"
	//언리얼 엔진에 전방 선언이라는 방법이 잇는데 각 파일에 헤더를 가져올때 파일을 붙여서 가져오는 방식 대신 부담을 덜해주는 방법 
	//앞에 class 만 붙여주면됨 단 사용할려는 클래스 위에 상위 상속 클래스의 헤더는 필수 이다.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components2", meta = (AllowPrivateAccess = "true"))
	USceneComponent* AttackSpawnPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TankStatus")
	float MovingSpeed;
};
