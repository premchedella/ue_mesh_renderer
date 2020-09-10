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
The plugin contains the following functionality:
* A new **Terrain Render** UI button in the UE Editor Tool.
* Open a File Dialog window selects DEM Elevation Data, which is a ASCII file.
* Parsing the DEM Elevation Data
* Rendering the DEM Elevation Data through Mesh.

### 2.2 Terrain Render UI Button
A new Terrain Render UI button in the UE Editor Tool.


* Add a new header, *TerrainRenderEditor.h* and source, *TerrainRenderEditor.h* file, where UE4 Editor has **Terrain Render** as a tool bar button.
* Add `"EditorStyle"` in the section of `PublicDependencyModuleNames.AddRange` in *TerrainRender.Build.cs* file (to solve the build error).
*  Added Code to build the **Terrain Render** button in the UE Editor tool.
* Compile the code.  Press F5, solve build error if any.

Following image shows the **Terrain Render** UI button that's added, which is shown in the red color highlighted.

<img src=./images/terrain_render_ui.JPG width=90%/>  

When user presses the **Terrain Render** UI button is pressed, following message displayed in the **Output Log** Window.  Output Log windows is displayed by selecting the **Window->Developer Tools-> Output Log**.

<img src=./images/terrain_render_ui_log.JPG width=90%/> 

### 2.3 File Open Dialog Box

Add code in the *TerrainRender.cpp* file to open the dialog box whenever **Terrain Render** UI button is pressed.  

Following image shows the file dialog box open whenever **Terrain Render** UI button is pressed.  

<img src=./images/file_open_dialog.PNG width=90%/> 

Following image shows the ASCII file that was opened/selected when file dialog box opened in the Log window.  

<img src=./images/file_open_dialog_log.PNG width=90%/> 

### 2.4 Parsing & Data
Add two new C++ modules, namely Dem Elevation Parser, and Dem Elevation Data.

These two classes are with the following steps:
* Press **Content Browser**
* Select **Add New** drop down box
* Select **C++ New Class**
* Select **None** radio box for choose Parent class and then press **Next**
* Give the **name** **(user has to define)** to the class and select **TerrainRender (Runtime)** and then Press **Create Class**

Dem Elevation Parser module takes input file and parses the input file and stored the parameters and data in Dem Elevation Data module, which is a singleton class.

**Note:** Don't manually add classes and follow the procedure as mentioned above otherwise build errors occurs.

Once the file is parsed then file data parameters are displayed in the **Output Log** window and following picture depicts the same.

<img src=./images/file_parse_log.PNG width=90%/>


### 2.5 Triangle Draw
To draw a triangle in the Unreal Engine using C++, **ProceduralMeshComponent** needs to be added in the public dependency build system, *terrain_mesh_rederer.Build.cs*

Add a new C++ module Triangle Draw :
* Press **Content Browser**
* Select **Add New** drop down box
* Select **C++ New Class**
* Select **Actor** radio box for choose Parent class and then press **Next**
* Give the **name, (DrawTraingle, user has to define)** to the class and select **terrain_mesh_rederer (Runtime)** and then Press **Create Class**.

In the header file, define **Category = "DrawTriangle"**, and fill the rest of the variables, and functions.  Compile the code, resolve if there are any build errors.

Create the Blue Print for the this class with the following insturctions.
* Press **Content Browser**
* Select **Add New** drop down box
* Select **BluePrint Class**
* Search in All class, Select **DrawTriangle**, and press **Select** button.
* Rename the BluePrint class to **DrawTriangle_BP**, by right clicking with the mouse.
* Drag the **DrawTriangle_BP** to World window, based on the code lower/upper triangle or Square will be displayed.

Following is the code to draw the triangles and square.


``` C++
  vertices.Add(FVector(0.0f, 100.0f, 0.0f));
  vertices.Add(FVector(0.0f, 0.0f, 0.0f));
  vertices.Add(FVector(100.0f, 0.0f, 0.0f));
  vertices.Add(FVector(100.0f, 100.0f, 0.0f));

  //Lower Triangle
  triangles.Add(0);
  triangles.Add(1);
  triangles.Add(2);

  //Upper Triangle

  triangles.Add(0);
  triangles.Add(2);
  triangles.Add(3);
```

The portion of Upper is commented, then Lower triangle is displayed in the world as shown in the following figure

<img src=./images/lower_triangle.PNG width=90%/>



The portion of Lower is commented, then Upper triangle is displayed in the world as shown in the following figure

<img src=./images/upper_triangle.PNG width=90%/>



The portions of both Lower and Upper makes a square, is displayed in the world as shown in the following figure

<img src=./images/upper_lower_triangle.PNG width=90%/>




## 3. References

Following are the reference:
1. [Unreal Project Create](https://docs.unrealengine.com/en-US/Engine/Basics/Projects/Browser/index.html)
1. [Unreal Plugin Create](https://docs.unrealengine.com/en-US/Programming/Plugins/index.html) 
1. [Unreal TArrays](https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TArrays/index.html)
1. [Unreal String Handling](https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/StringHandling/index.html)
1. [Unreal File Open Dialog](https://docs.unrealengine.com/en-US/API/Developer/DesktopPlatform/IDesktopPlatform/OpenFileDialog/1/index.html)
1. [Unreal File Opening/Reading](https://docs.unrealengine.com/en-US/API/Runtime/Core/Misc/FFileHelper/index.html)
1. [Editor Plugin](http://wlosok.cz/editor-plugins-in-ue4-1-intro/)
1. [Editor Plugin](https://lxjk.github.io/2019/10/01/How-to-Make-Tools-in-U-E.html)
1. [Procedural Mesh Component](http://wlosok.cz/procedural-mesh-in-ue4-1-triangle/)

## 4. TODO
1. In the Plugin, Get the class of *DrawTriangle_BP* and invoke that class in the World, draw the Triangle with out manually.  Following is the code, need to explore on this.

```
 #include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
 
 static ConstructorHelpers::FClassFinder<AActor> DrawTriangleOb(TEXT("/Game/DrawTriangle_BP"));
UBlueprintGeneratedClass* TriangleClass = Cast<UBlueprintGeneratedClass>(DrawTriangleOb.Class);
UBlueprint* TriangleBlueprint = Cast<UBlueprint>(TriangleClass->ClassGeneratedBy);
 
TriangleBlueprint->GetName()->ToString();
```

2. Create another class based on the **ProceduralMeshComponent**, get the data from the Dem Elevation Data module , prepare the mesh and invoke the new class in the world that shows the mesh of file.
3. Get the *Get World Origin Location* function and use this while drawing.













