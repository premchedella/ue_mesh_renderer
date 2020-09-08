// Fill out your copyright notice in the Description page of Project Settings.


#include "DemElevationParser.h"

#include "DemElevationData.h"

DemElevationParser::DemElevationParser(FString Name)
{
  FileName = Name;
}

DemElevationParser::~DemElevationParser()
{

}

void DemElevationParser::Parse()
{
  UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: Parse Function Called."));

  DemElevationData* DemElevation = DemElevationData::Instance();
  DemElevation->SetFileName(FileName);

  UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: File Name = %s"), *FileName);
  FString FileData;

  //Open the File
  if (FFileHelper::LoadFileToString(FileData, *FileName))
  {
    UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: File Opened."));

    TArray<FString> LinesData;
    FString Seperator = "\n";  // New Line
    int32 NumLines = 0;

    //Get the File Data to Line Data (for each Line)
    NumLines = FileData.ParseIntoArray(LinesData, *Seperator);

    UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: Number of Lines = %d"),
      NumLines);

    ParseParameters(LinesData);
    ParaseData(LinesData);

  } else
  {
    UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: File Not able to open."));
  }

}

void DemElevationParser::ParseParameters(const TArray<FString>& LinesData)
{
  DemElevationData* DemElevation = DemElevationData::Instance();
  for (int LineIndex = 0; LineIndex < 6; LineIndex++)
  {
    FString LineData = LinesData[LineIndex];
    FString Key;
    FString Value;
    ParseLineData(LineData, Key, Value);
    UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: Key = %s, Value = %s"),
        *Key, *Value);

    if (Key.Equals(TEXT("ncols")))
    {
      int32 DataValue = FCString::Atoi(*Value);
      DemElevation->SetNumCols(DataValue);
    } else if (Key.Equals(TEXT("nrows")))
    {
      int32 DataValue = FCString::Atoi(*Value);
      DemElevation->SetNumRows(DataValue);
    } else if (Key.Equals(TEXT("xllcorner")))
    {
      int32 DataValue = FCString::Atoi(*Value);
      DemElevation->SetXCorner(DataValue);
    } else if (Key.Equals(TEXT("yllcorner")))
    {
      int32 DataValue = FCString::Atoi(*Value);
      DemElevation->SetYCorner(DataValue);
    } else if (Key.Equals(TEXT("cellsize")))
    {
      float DataValue = FCString::Atof(*Value);
      DemElevation->SetCellSize(DataValue);
    } else if (Key.Equals(TEXT("NODATA_value")))
    {
      int32 DataValue = FCString::Atoi(*Value);
      DemElevation->SetNoData(DataValue);
    }
  }
}

void DemElevationParser::ParseLineData(const FString& LineData, FString& Key,
    FString& Value)
{
  FString Seperator = " ";  //Space
  TArray<FString> WordsData;
  int32 NumWords = LineData.ParseIntoArray(WordsData, *Seperator);
  Key = WordsData[0];
  Value = WordsData[1];
}

void DemElevationParser::ParaseData(const TArray<FString>& LinesData)
{
  TArray<TArray<int32>> RowColData;

  for (int LineIndex = 6; LineIndex < LinesData.Num(); LineIndex++)
  {
    FString LineData = LinesData[LineIndex];
    FString Seperator = " ";  //Space
    TArray<FString> WordsData;
    int32 NumWords = LineData.ParseIntoArray(WordsData, *Seperator);

    TArray<int32> RowData;

    //Don't consider the last one as it has empty value.

    for (int RowCount = 0; RowCount < (NumWords - 1); RowCount++)
    {
      int32 DataValue = FCString::Atoi(*WordsData[RowCount]);
      RowData.Add(DataValue);
    }

    RowColData.Add(RowData);
  }

  UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: Number of Colums = %d "),
      RowColData.Num());
  UE_LOG(LogTemp, Warning, TEXT("Dem Elevation Parser: Values in Each Row = %d "),
      RowColData[0].Num());

  
  DemElevationData* DemElevation = DemElevationData::Instance();
  DemElevation->SetData(RowColData);
}

