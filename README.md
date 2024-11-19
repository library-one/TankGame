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
  
