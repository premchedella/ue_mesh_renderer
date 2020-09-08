// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TERRAINRENDER_API DemElevationData
{
public:
  static DemElevationData* Instance();
  void Release();

  void SetFileName(const FString& FileName);
  FString GetFileName();
  void SetNumCols(int32 value);
  void SetNumRows(int32 value);
  void SetXCorner(int32 value);
  void SetYCorner(int32 value);
  void SetNoData(int32 value);
  void SetCellSize(float value);
  void SetData(TArray<TArray<int32>> data);

  int32 GetNumCols();
  int32 GetNumRows();
  int32 GetXCorner();
  int32 GetYCorner();
  int32 GetNoData();
  float GetCellSize();
  TArray<TArray<int32>> GetData();

private:
  DemElevationData();
  ~DemElevationData();

  static DemElevationData* instance_;
  FString FileName;
  int32 NoCols;
  int32 NoRows;
  int32 XCorner;
  int32 YCorner;
  int32 NoData;
  float CellSize;
  TArray<TArray<int32>> ElevationData;
};
