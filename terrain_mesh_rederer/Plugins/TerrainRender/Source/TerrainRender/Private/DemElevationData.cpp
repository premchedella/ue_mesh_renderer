// Fill out your copyright notice in the Description page of Project Settings.


#include "DemElevationData.h"

DemElevationData* DemElevationData::instance_ = NULL;

DemElevationData* DemElevationData::Instance()
{
  if (instance_ == NULL)
  {
    instance_ = new DemElevationData();
  }
  return instance_;
}

void DemElevationData::Release()
{

}

void DemElevationData::SetFileName(const FString& Name)
{
  FileName = Name;
}

FString DemElevationData::GetFileName()
{
  return FileName;
}

void DemElevationData::SetNumCols(int32 value)
{
  NoCols = value;
}

void DemElevationData::SetNumRows(int32 value)
{
  NoRows = value;
}

void DemElevationData::SetXCorner(int32 value)
{
  XCorner = value;
}

void DemElevationData::SetYCorner(int32 value)
{
  YCorner = value;
}

void DemElevationData::SetNoData(int32 value)
{
  NoData = value;
}

void DemElevationData::SetCellSize(float value)
{
  CellSize = value;
}

void DemElevationData::SetData(TArray<TArray<int32>> data)
{
  ElevationData = data;
}

int32 DemElevationData::GetNumCols()
{
  return NoCols;
}

int32 DemElevationData::GetNumRows()
{
  return NoRows;
}

int32 DemElevationData::GetXCorner()
{
  return XCorner;
}

int32 DemElevationData::GetYCorner()
{
  return YCorner;
}

int32 DemElevationData::GetNoData()
{
  return NoData;
}

float DemElevationData::GetCellSize()
{
  return CellSize;
}

TArray<TArray<int32>> DemElevationData::GetData()
{
  return ElevationData;
}

DemElevationData::DemElevationData()
{
  FileName = TEXT("");
  NoCols = 0;
  NoRows = 0;
  XCorner = 0;
  YCorner = 0;
  NoData = 0;
  CellSize = 0.0f;

}

DemElevationData::~DemElevationData()
{
}
