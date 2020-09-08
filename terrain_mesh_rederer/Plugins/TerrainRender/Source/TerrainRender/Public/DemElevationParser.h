// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TERRAINRENDER_API DemElevationParser
{
public:
	DemElevationParser(FString Name);
	~DemElevationParser();

  void Parse();

private:

  void ParseParameters(const TArray<FString>& LinesData);
  void ParseLineData(const FString& LineData, FString& Key, FString& Value);
  void ParaseData(const TArray<FString>& LinesData);


  FString FileName;
};
