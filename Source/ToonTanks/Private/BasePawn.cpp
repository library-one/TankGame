// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//ï¿½ï¿½ï¿? ï¿½ï¿½ï¿½Ï¿ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ö¼Ò°ï¿½ï¿½ï¿½ cppï¿½ï¿½ï¿½ï¿½ï¿½Ú¿ï¿½ï¿½ï¿½ ï¿½Ö¾ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ã¸ï¿½ ï¿½Ô¼ï¿½ï¿½ï¿½ createdefaultsubobjectï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ö¼Ò¸ï¿½ ï¿½Ö¾ï¿½ï¿½ï¿½
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(CapsuleComp);

	AttackSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	AttackSpawnPoint->SetupAttachment(TurretMesh);

}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	//FVector °ª Áï °¡¸£Å°´Â °÷ÀÇ ÁÂÇ¥°ªÀ» ¶óÀÎ Æ®·¹ÀÌ½ÌÀÇ HitResult °ª¿¡¼­ ¿¢ÅÍÀÇ À§Ä¡ °ªÀ» »©¸é ÁÂÇ¥°ªÀÌ ³ª¿È
	FVector ToTarget =LookAtTarget - TurretMesh->GetComponentLocation();
	//ToTarget ÀÇ ÁÂÇ¥°ª ¸¸Å­ Pitch , Yaw , Roll ÀÇ È¸Àü°ªÀ» Áà¼­ ±× È¸Àü°ªÀ» ÀúÀåÇÔ RotatorÀº À¯¸íÇÑ È¸Àü°ª ÀúÀå ±¸Á¶Ã¼ÀÓ 
	//¹Ù´Ú°ú ÆòÇàÇÏ°Ô È¸Àü ½ÃÅ°°í ½ÍÀ½À¸·Î Pitch °ª°ú Roll °ªÀº 0À¸·Î ¼³Á¤ È¸Àü°ªÀÇ Yaw °ª¸¸ º¯°æ 
	FRotator LookAtRotation = FRotator(0.f,ToTarget.Rotation().Yaw,0.f);

	//È¸Àü °ªÀ» ÇÒ´ç ÇÒ¶§ ¿ùµå½ºÆäÀÌ½ºÀÇ ÁÂÇ¥°ª¿¡¼­ ¿¢ÅÍÀÇ ÁÂÇ¥°ªÀ» »« °ªÀ» º¯°æÇÏ¿© È¸Àü ½ÃÅ°±â ¶§¹®¿¡
	//LocalOffsetÀÌ ¾Æ´Ñ WorldRotation À¸·Î °ªÀ» ³Ö¾îÁÖ´Â°Ô ¸ÂÀ½ ¿¢ÅÍ¸¦ ±âÁØÀ¸·Î ¿ùµå½ºÆäÀÌ½ºÀÇ ÁÂÇ¥·Î ÀÌµ¿½ÃÅ°±â ¶§¹®ÀÌ´Ù.
	//RInterTo º¸°£ ÇÔ¼ö¸¦ »ç¿ëÇØ È¸ÀüÀ» ´õ ºÎµå·´°Ô ¸¸µê
	TurretMesh->SetWorldRotation(FMath::RInterpTo(
								TurretMesh->GetComponentRotation(),LookAtRotation,
								UGameplayStatics::GetWorldDeltaSeconds(this),5.f));
}