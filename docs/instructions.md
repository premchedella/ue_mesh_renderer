# Instructions

## 1. Create Unreal Project

Follow the instructions, first launch the Unreal Engine (In my case 4.25.1 Visual Studio 2017 project (UE4.sln):

* Select Games, Press Next
* Select Blank, Press Next
* Project Settings
  * C++ Project (Choose whether to create a Blue Print or C++ project)
  * Maximum Quality (Choose the performance characteristics of your project)
  * Raytracing Enabled
  * Dektop/Console
  * No Starter Content
  * Select the name of the project and folder.
  * Name of the project **terrain_mesh_rederer**.
  * Press **Create Project** button.
* A Project is created with **terrain_mesh_rederer.uproject**,  **terrain_mesh_rederer.sln**, and necessary files .  Visual Studio 2017 automatically launches solution and compiles.
* Otherwise go to the project folder and select the **terrain_mesh_rederer.uproject** and convert to Visual Studio  2017 project and then compile.
* Takes sometime to compile the project.
* Once the project is compiled then press F5 in the Visual Studio the following image is displayed.


<img src=./images/initital_project_creation_output.JPG width=90%/>


## 2. Plugins

In UE4 (Unreal Engine 4), Plugins are collections of code and data that developers can easily enable or disable within the Editor on a per-project basis. Plugins can add runtime gameplay functionality, modify built-in Engine features (or add new ones), create new file types, and extend the capabilities of the Editor with new menus, tool bar commands, and sub-modes. Many existing UE4 subsystems were designed to be extensible using Plugins. 

### 2.1 Create Plugin

Following are instruction to create a Plug-in:

* Go to **Edit** Menu button in the UE Editor
* Select **Plugin** button
* Select **New Plugin** button
* Select **Blank**, give name is **TerrainRender**, don't select Is Engine Plugin, and then **Press Create** Plugin.

The Visual Studio stops and reload the Visual Studio again.  A new plugin **TerrainRender** is created, can see **Plugins** section in the Solutions Explorer.

The source code for the Plugins are available at *Plugins\TerrainRender\Source\TerrainRender*.  It contains * *. Build.cs* file, *Private* and *Public* folders.  Normally *Private* folder contains **.h* files and *Public* folder cotains *.cpp* files.

### 2.1 Develop Plugin
* Add a new header, *TerrainRenderEditor.h* and source, *TerrainRenderEditor.h* file, where UE4 Editor has **Terrain Render** as a tool bar button.
* Add `"EditorStyle"` in the section of `PublicDependencyModuleNames.AddRange` in *TerrainRender.Build.cs* file (to solve the build error).
*  Added Code to build the **Terrain Render** button in the UE Editor tool.
* Compile the code.  Press F5, solve build error if any.

Following is the **Terrain Render** UI button that's added, which is shown in the red color highlighted.

<img src=./images/terrain_render_ui.JPG width=90%/>  

When user presses the **Terrain Render** UI button is pressed, following message displayed in the **Output Log** Window.  Output Log windows is displayed by selecting the **Window->Developer Tools-> Output Log**.

<img src=./images/terrain_render_ui_log.JPG width=90%/> 

























