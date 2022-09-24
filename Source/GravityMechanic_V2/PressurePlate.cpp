// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	PressurePlateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PressurePlateMesh"));
	PressurePlateMesh->SetupAttachment(RootComponent);
	
	PressureTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("PressureTrigger"));
	PressureTrigger->SetupAttachment(RootComponent);

	ArrivalScenePoint = CreateDefaultSubobject<USceneComponent>(TEXT("ArrivalScenePoint"));
	ArrivalScenePoint->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();

	DefaultRelativeLocation = PressurePlateMesh->GetRelativeLocation();

	//LinkedGate = UGameplayStatics::GetActorOfClass(this, LinkedGateClass);
	
}

// void APressurePlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// 	if (LinkedGate)
// 	{
// 		
// 		LinkedGate->MoveGate(true);
// 	
// 		const FRotator ZeroRotator;
// 		const TEnumAsByte<EMoveComponentAction::Type> MoveAction = EMoveComponentAction::Move;
// 		const FLatentActionInfo LatentInfo;
// 	
// 		UKismetSystemLibrary::MoveComponentTo(PressurePlateMesh, ArrivalScenePoint->GetRelativeLocation(), ZeroRotator, true, true, 1.0f,
// 			false, MoveAction, LatentInfo);
// 	}
// 	
// }
//
// void APressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
// {
// 	if (LinkedGate)
// 	{
// 		LinkedGate->MoveGate(false);
// 	
// 		const FRotator ZeroRotator;
// 		const TEnumAsByte<EMoveComponentAction::Type> MoveAction = EMoveComponentAction::Move;
// 		const FLatentActionInfo LatentInfo;
// 	
// 		UKismetSystemLibrary::MoveComponentTo(PressurePlateMesh, DefaultRelativeLocation, ZeroRotator, true, true, 1.0f,
// 			false, MoveAction, LatentInfo);
// 	}
// }
//
// void APressurePlate::ActivatePlate(bool bActivate)
// {
// 	if (LinkedGate != nullptr)
// 	{
// 		if (bActivate)
// 		{
// 			UE_LOG(LogTemp, Warning, TEXT("Open"))
// 			LinkedGate->MoveGate(true);
// 	
// 			const FRotator ZeroRotator;
// 			const TEnumAsByte<EMoveComponentAction::Type> MoveAction = EMoveComponentAction::Move;
// 			const FLatentActionInfo LatentInfo;
// 	
// 			UKismetSystemLibrary::MoveComponentTo(PressurePlateMesh, ArrivalScenePoint->GetRelativeLocation(), ZeroRotator, true, true, 1.0f,
// 				false, MoveAction, LatentInfo);
// 		}
// 		else
// 		{
// 			LinkedGate->MoveGate(false);
// 	
// 			const FRotator ZeroRotator;
// 			const TEnumAsByte<EMoveComponentAction::Type> MoveAction = EMoveComponentAction::Move;
// 			const FLatentActionInfo LatentInfo;
// 	
// 			UKismetSystemLibrary::MoveComponentTo(PressurePlateMesh, DefaultRelativeLocation, ZeroRotator, true, true, 1.0f,
// 				false, MoveAction, LatentInfo);
// 		}
// 	}
// }
//

