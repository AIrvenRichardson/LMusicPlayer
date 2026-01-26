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
static void PauseButton();
static void NextButton();
static void PrevButton();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 410;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "lmusiclayout");

    // lmusiclayout: controls initialization
    //----------------------------------------------------------------------------------
    bool LMusicPlayerActive = true;
    float VolumeSliderValue = 100.0f;
    bool ShuffleEnabledChecked = false;
    bool LoopEnabledChecked = false;
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //GuiSetStyle(DEFAULT, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
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
                GuiLabel((Rectangle){ 25, 20, 120, 24 }, "Now Playing: X");
                if (GuiButton((Rectangle){ screenWidth/2-60, screenHeight-30, 120, 24 }, "Pause")) PauseButton(); 
                if (GuiButton((Rectangle){ screenWidth/2+60, screenHeight-30, 120, 24 }, ">>")) NextButton(); 
                if (GuiButton((Rectangle){ screenWidth/2-180, screenHeight-30, 120, 24 }, "<<")) PrevButton(); 
                GuiSliderBar((Rectangle){ screenWidth-145, 20, 120, 16 }, NULL, NULL, &VolumeSliderValue, 0, 100);
                GuiLabel((Rectangle){ screenWidth-170, 20, 112, 16 }, "Vol:");
                GuiPanel((Rectangle){ 25, 50, 360, 360 }, NULL);
                GuiCheckBox((Rectangle){ screenWidth-48, 410-24, 24, 24 }, "Shuffle", &ShuffleEnabledChecked);
                GuiCheckBox((Rectangle){ screenWidth-72, 410-24, 24, 24 }, "Loop", &LoopEnabledChecked);
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
static void PauseButton()
{
    // TODO: Implement control logic
}

static void NextButton()
{
    // TODO: Implement control logic
}

static void PrevButton()
{
    // TODO: Implement control logic
}