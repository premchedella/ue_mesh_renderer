// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawTraingle.h"

// Sets default values
ADrawTraingle::ADrawTraingle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  pm = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
  pm->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void ADrawTraingle::OnConstruction(const FTransform& Transform)
{
  vertices.Add(FVector(0.0f, 100.0f, 0.0f));
  vertices.Add(FVector(0.0f, 0.0f, 0.0f));
  vertices.Add(FVector(100.0f, 0.0f, 0.0f));
  vertices.Add(FVector(100.0f, 100.0f, 0.0f));


  //Lower Triangle
  triangles.Add(0);
  triangles.Add(1);
  triangles.Add(2);


  //Upper Triangle

  triangles.Add(0);
  triangles.Add(2);
  triangles.Add(3);


  //uvs.Init(FVector2D(0.0f, 0.0f), 3);
  uvs.Add(FVector2D(0.0f, 0.0f));
  uvs.Add(FVector2D(1.0f, 0.0f));
  uvs.Add(FVector2D(0.0f, 1.0f));

  normals.Init(FVector(0.0f, 0.0f, 1.0f), 3);
  vertexColors.Init(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f), 3);
  tangents.Init(FProcMeshTangent(1.0f, 0.0f, 0.0f), 3);

  //Function that creates mesh section
  pm->CreateMeshSection_LinearColor(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
}

void ADrawTraingle::ClearMeshData()
{
  vertices.Empty();
  triangles.Empty();
  uvs.Empty();
  normals.Empty();
  vertexColors.Empty();
  tangents.Empty();
}

