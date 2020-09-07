#include "TerrainRenderEditor.h"

#include "TerrainRender.h"


#define LOCTEXT_NAMESPACE "FTerrainRenderModule"

void FTerrainRenderEditor::RegisterCommands()
{
  UI_COMMAND(TerrainRenderCommand, "Terrain\nRender", 
      "Renders Terrain Mesh",
      EUserInterfaceActionType::Button, FInputGesture());  
}

#undef LOCTEXT_NAMESPACE