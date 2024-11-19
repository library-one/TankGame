// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));

	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 600.0f;
	Value = 0;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	//사용할 APlayerController은 포인터 이기 때문에 주소로 초기화 해줘야됨
	//근데 GetController()은 AController 이기 때문에 부모 클래스의 주소 임으로 못가져옴
	// 따라서 Acontroller 을 다운캐스팅 해줘야됨 하위로 
	//Cast<변환클래스>(Pointer)
	PlayerControllerRef = Cast<APlayerController>(GetController());


}


// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//모든 포인터는 초기화해 사용하기전 if(Pointer) 구문으로 반환값이 null 인지 true 인지 확인해야 됨
	//라인 트레이싱 에 히트 이벤트의 결과를 가져오기 위한 구문 
	if(PlayerControllerRef){
		//히트이벤트의 결과를 가져오기 위한 변수 참조형이라 결과에 따라 반환 구문이 다름 ex)HitResult.Actor , HitResult.ImpactPoint
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);

		//DrawDebugHelpers 의 디버그구체 라이브러리 가져와 사용 
		DrawDebugSphere(GetWorld(),
		HitResult.ImpactPoint,
		25.0f,
		12,
		FColor::Blue,
		false,
		-1.0f);
		//basePawn 에서 (부모 클래스) 선언한 함수를 이용하여 상체 회전 
		RotateTurret(HitResult.ImpactPoint);
		}
	
}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float value)
{
	// 뒤로 가기 위해선 Move의 뒤로 갈때의 value를 저장해야됨
	this->Value = value;
	FVector DeltaLocation = FVector::ZeroVector;
	// x = value * deltatime * speed
	DeltaLocation.X = value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation,true);
}

void ATank::Turn(float value)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	// 뒤로 갈때
	if (Value == -1)
	{
		// 반대 방향
		//  Yaw = value * Deltatime * speed
		DeltaRotator.Yaw = -1 * value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(DeltaRotator);
	}
	// 앞으로 갈때
	//  정방향
	else
	{
		DeltaRotator.Yaw = value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(DeltaRotator);
	}
}
