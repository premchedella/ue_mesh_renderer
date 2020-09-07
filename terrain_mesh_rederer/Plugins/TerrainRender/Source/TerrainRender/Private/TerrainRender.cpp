// Copyright Epic Games, Inc. All Rights Reserved.

#include "TerrainRender.h"

#include "TerrainRenderEditor.h"
#include "LevelEditor.h"

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
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTerrainRenderModule, TerrainRender)