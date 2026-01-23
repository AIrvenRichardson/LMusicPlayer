/*******************************************************************************************
*
*   Lmusiclayout v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 AIrvenRIchardson. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void Button();
static void Button();
static void Button();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "lmusiclayout");

    // lmusiclayout: controls initialization
    //----------------------------------------------------------------------------------
    bool LMusicPlayerActive = true;
    float Volume SliderValue = 0.0f;
    bool ShuffleEnabledChecked = false;
    bool LoopEnabledChecked = false;
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            if (LMusicPlayerActive)
            {
                LMusicPlayerActive = !GuiWindowBox((Rectangle){ 280, 136, 608, 456 }, "LMusic");
                GuiLabel((Rectangle){ 528, 480, 120, 24 }, "Now Playing: X");
                if (GuiButton((Rectangle){ 512, 512, 120, 24 }, "Pause")) Button(); 
                if (GuiButton((Rectangle){ 640, 512, 120, 24 }, ">>")) Button(); 
                if (GuiButton((Rectangle){ 384, 512, 120, 24 }, "<<")) Button(); 
                GuiSliderBar((Rectangle){ 752, 176, 120, 16 }, NULL, NULL, &Volume SliderValue, 0, 100);
                GuiLabel((Rectangle){ 728, 168, 112, 16 }, "Vol:");
                GuiPanel((Rectangle){ 384, 208, 376, 272 }, NULL);
                GuiCheckBox((Rectangle){ 312, 512, 24, 24 }, "Shuffle", &ShuffleEnabledChecked);
                GuiCheckBox((Rectangle){ 312, 552, 24, 24 }, "Loop", &LoopEnabledChecked);
            }
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
static void Button()
{
    // TODO: Implement control logic
}
static void Button()
{
    // TODO: Implement control logic
}
static void Button()
{
    // TODO: Implement control logic
}

