// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ProceduralMeshComponent.h"

#include "DrawTraingle.generated.h"

UCLASS()
class TERRAIN_MESH_REDERER_API ADrawTraingle : public AActor
{
	GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, Category = "DrawTriangle")
    UProceduralMeshComponent* pm;
	
public:	
	// Sets default values for this actor's properties
	ADrawTraingle();

  UPROPERTY()
    TArray<FVector> vertices;
  UPROPERTY()
    TArray<FVector> normals;
  UPROPERTY()
    TArray<int32> triangles;
  UPROPERTY()
    TArray<FVector2D> uvs;
  UPROPERTY()
    TArray<FLinearColor> vertexColors;
  UPROPERTY()
    TArray<FProcMeshTangent> tangents;

  virtual void OnConstruction(const FTransform& Transform) override;

  void ClearMeshData();
};
