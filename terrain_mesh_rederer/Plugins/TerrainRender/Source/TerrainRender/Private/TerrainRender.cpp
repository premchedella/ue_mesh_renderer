// Copyright Epic Games, Inc. All Rights Reserved.

#include "TerrainRender.h"

#include "TerrainRenderEditor.h"
#include "LevelEditor.h"

#include "DemElevationParser.h"
#include "DemElevationData.h"

// File Open Diaglog includes
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"

#define LOCTEXT_NAMESPACE "FTerrainRenderModule"

void FTerrainRenderModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
  FTerrainRenderEditor::Register();

  PluginCommands = MakeShareable(new FUICommandList);
  
  PluginCommands->MapAction(
    FTerrainRenderEditor::Get().TerrainRenderCommand,
    FExecuteAction::CreateRaw(this, &FTerrainRenderModule::TerrainRenderAction)
  );

  UpdateToolBar();
}

void FTerrainRenderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
  FTerrainRenderEditor::Unregister();
}


void FTerrainRenderModule::UpdateToolBar()
{
  FLevelEditorModule& LevelEditorModule =
    FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

  TSharedPtr<FExtender> NewToolbarExtender = MakeShareable(new FExtender);

  NewToolbarExtender->AddToolBarExtension("Content",
    EExtensionHook::Before,
    PluginCommands,
    FToolBarExtensionDelegate::CreateRaw(this,
      &FTerrainRenderModule::AddToolbarButton));

  LevelEditorModule.GetToolBarExtensibilityManager()->
    AddExtender(NewToolbarExtender);
}

void FTerrainRenderModule::AddToolbarButton(FToolBarBuilder& Builder)
{
  Builder.AddSeparator();
  Builder.AddToolBarButton(FTerrainRenderEditor::Get().TerrainRenderCommand);
}

void FTerrainRenderModule::TerrainRenderAction()
{
  UE_LOG(LogTemp, Warning, TEXT("Terrain Render Button Pressed.!!!"));

  FString FileName = GetFileName();
  FileParse(FileName);

  PrintData();

  
}

FString FTerrainRenderModule::GetFileName()
{
  FString FileName = "";

  IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
  if (DesktopPlatform)
  {
    //A value of 0 represents single file selection while a value of 1 represents multiple file selection
    uint32 SelectionFlag = 0;
    FString DialogTitle = FString("DEM Elevation");
    FString DefaultPath = FString(".");
    FString FileTypes = FString("Text Files | *.asc");
    TArray<FString> OutFileNames;
    DesktopPlatform->OpenFileDialog(NULL,
      DialogTitle, DefaultPath,
      FString(""),
      FileTypes,
      SelectionFlag,
      OutFileNames);

    if (OutFileNames.Num() > 0)
    {
      UE_LOG(LogTemp, Warning, TEXT("File Dialog: Opened File = %s"),
          *OutFileNames[0]);
      FileName = OutFileNames[0];
    }
  }

  return FileName;
}

void FTerrainRenderModule::FileParse(const FString& FileName)
{
  DemElevationParser parser(FileName);
  parser.Parse();
}

void FTerrainRenderModule::PrintData()
{
  DemElevationData* DemElevation = DemElevationData::Instance();

  int32 NoCols = DemElevation->GetNumCols();
  UE_LOG(LogTemp, Warning, TEXT("Mesh: No. Cols = %d"), NoCols);

  int32 NoRows = DemElevation->GetNumRows();
  UE_LOG(LogTemp, Warning, TEXT("Mesh: No. Rows = %d"), NoRows);

  int32 XCorner = DemElevation->GetXCorner();
  UE_LOG(LogTemp, Warning, TEXT("Mesh: X Lower Level Corner = %d"), XCorner);

  int32 YCorner = DemElevation->GetXCorner();
  UE_LOG(LogTemp, Warning, TEXT("Mesh: Y Lower Level Corner = %d"), YCorner);

  int32 NoData = DemElevation->GetNoData();
  UE_LOG(LogTemp, Warning, TEXT("Mesh: No Data Value = %d"), NoData);

  float CellSize = DemElevation->GetCellSize();
  UE_LOG(LogTemp, Warning, TEXT("Mesh: Cell Size = %f"), CellSize);

  TArray<TArray<int32>> ElevationData = DemElevation->GetData();

  UE_LOG(LogTemp, Warning, TEXT("Mesh: Number of Colums = %d "),
      ElevationData.Num());
  UE_LOG(LogTemp, Warning, TEXT("Mesh: Values in Each Row = %d "),
      ElevationData[0].Num());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTerrainRenderModule, TerrainRender)