#pragma once

#include "SlateBasics.h"

#include "EditorStyleSet.h"


class FTerrainRenderEditor : public TCommands<FTerrainRenderEditor>
{
public:

  FTerrainRenderEditor()
    : TCommands<FTerrainRenderEditor>
    (
      TEXT("TerrainRenderEditor"),
      NSLOCTEXT("Contexts", "TerrainRenderEditor", "TerrainRenderEditor Plugin"),
      NAME_None,      
      FEditorStyle::GetStyleSetName()
      ) {}

  virtual void RegisterCommands() override;

public:

  TSharedPtr<FUICommandInfo> TerrainRenderCommand;  
};
