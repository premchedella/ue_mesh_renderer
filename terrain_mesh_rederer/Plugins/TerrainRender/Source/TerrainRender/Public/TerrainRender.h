// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FReply;

class FTerrainRenderModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
  TSharedPtr<class FUICommandList> PluginCommands;

  void UpdateToolBar();
  void AddToolbarButton(FToolBarBuilder& Builder);  
  void TerrainRenderAction();
};
