# TankGame
#
- BasePawn 클래스 생성 - 플레이어 , 적AI 기본 틀
- RootComponent(CapsuleComponent) 에 머리(StaticMeshComponent(발사,USceneComponet)) 몸통 (StaticMeshComponent(이동)) 결합하여 각 트랜스폼에 맞춰 이동 RootComponent는 Attachment를 지원
![image](https://github.com/user-attachments/assets/7afd16b5-3e23-4be2-8e2a-7725abdf48f6)
# 
- UPROPERTY()접근지정자 지정 가능자
- static mesh component 각각 turret, base 지정 완료 
- level 에 turret, tank 지정 완료
- basecase 상속 받은 tank c++ 생성
- VisibleAnywhere , Category = "CameraComponent" spring arm 과 camera rootcomponent 에 부착
- player input 생성
# 
- inputComponent 를 이용한 움직임 구현 
- AddActorLocalOffset 함수를 이용한 엑터의 로컬 좌표계 이동 구현
- 속도 = Speed(EditAnywhere) x value x DeltaTime 을 곱하여 이동 속도 계산 (UGamePlayStatics::GetWorldDeltaSecodns(this))
- 회전 = AddActorRotator 를 사용하여 회전 FRotator 클래스 사용 

# 
- 라인 트레이싱을 이용해 Hit Event 를 DrawDebugSphere 로 간단하게 시각화 함 
- Block Volume 으로 Hit Event 구역 설정
- BasePawn 에 RotateTurret 으로 Tank 와 Enemy 둘다 상체 회전 설정
  - emeny 은 FireRange 와 FVector::Dist() 로 Tank 와의 거리 감지 후 상체 움직임
  - Tank 는 GetController 을 받아 클래스 함수인 GetHitResultUnderCursor(콜리전 채널, bool , HitResult) 로 HitResult 의 지점을 설정해 부모의 RotateTurret함수에 인자값을 집어넣어 상체 회전

#
- Turret 발사 딜레이를 위한 Timer 함수 사용 TimerManager을 통해 SetTimer() 안의 인자 값으로 조절 Begin()에 생성
- emeny 가 감지 시 2초마다 발사 
- 발사체 Projectile  클래스 및 bp 생성
- basePawn 에 SpawnActor을 통한 발사체 생성
- Hit Event 안 OnComponentHit 이란 멀티캐스트 델리게이트 함수 생성 -> 관련 함수에 인자 전달 -> 발사체 충돌 확인

#
- Health Component 생성
- Health Component 에 OnTakeDamage 멀티케스트 델리게이트 생성 전달 -> ApplyDamage
