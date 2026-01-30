/*******************************************************************************************
*
*   LMusicPlayer v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2026 AIrvenRIchardson. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION

#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "gui_window_file_dialog.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void PauseButton();
static void NextButton();
static void PrevButton();
static void MenuButton();
static void LoopButton();
static void ShuffleButton();

//------------------------------------------------------------------------------------
// Global Controls Variables Declaration
//------------------------------------------------------------------------------------
bool ShuffleEnabledChecked = false;
bool LoopEnabledChecked = false;
bool Paused = false;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 410;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Music Player");

    // lmusiclayout: controls initialization
    //----------------------------------------------------------------------------------
    bool LMusicPlayerActive = true;
    float VolumeSliderValue = 100.0f;
    //----------------------------------------------------------------------------------
    
    // Gui file dialog initialization
    GuiWindowFileDialogState fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());
    char fileNameToLoad[1024] = { 0 };
    Texture texture = { 0 }; //Just gonna load an image for testing

    SetTargetFPS(60);
    GuiLoadStyle("style_cyber.rgs"); // Load raygui style file
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (fileDialogState.SelectFilePressed)
        {
            if (IsFileExtension(fileDialogState.fileNameText, ".png") || IsFileExtension(fileDialogState.fileNameText, ".jpg"))
            {
                strcpy(fileNameToLoad, TextFormat("%s/%s", fileDialogState.dirPathText, fileDialogState.fileNameText));
                // Load texture from file
                if (texture.id != 0) UnloadTexture(texture); // Unload previous texture
                texture = LoadTexture(fileNameToLoad);
                printf("Loaded file: %s\n", fileNameToLoad);
            }
            fileDialogState.SelectFilePressed = false;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            if (fileDialogState.windowActive) GuiLock();

            if (LMusicPlayerActive)
            {
                GuiLabel((Rectangle){ 25, 20, 120, 24 }, "Now Playing: X");
                if (GuiButton((Rectangle){ screenWidth/2-12, screenHeight-30, 24, 24 }, "#132#")) PauseButton(); 
                if (GuiButton((Rectangle){ screenWidth/2+36, screenHeight-30, 24, 24 }, "#134#")) NextButton(); 
                if (GuiButton((Rectangle){ screenWidth/2-60, screenHeight-30, 24, 24 }, "#129#")) PrevButton(); 
                if (GuiButton((Rectangle){ 25, screenHeight-30, 24, 24 }, "#78#")) ShuffleButton(); 
                if (GuiButton((Rectangle){ screenWidth-48, screenHeight-30, 24, 24 }, "#74#")) LoopButton(); 
                if (GuiButton((Rectangle){ 0, 0, 24, 24 }, "#141#")) fileDialogState.windowActive = true;
                GuiSliderBar((Rectangle){ screenWidth-145, 20, 120, 16 }, NULL, NULL, &VolumeSliderValue, 0, 100);
                GuiLabel((Rectangle){ screenWidth-170, 20, 112, 16 }, "Vol:");
                GuiPanel((Rectangle){ 25, 50, 360, 360 }, NULL);
                DrawTexture(texture, 25, 50, WHITE);
            }

            GuiUnlock();
            GuiWindowFileDialog(&fileDialogState);

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
    Paused = !Paused;
    printf(Paused ? "Music Paused\n" : "Music Resumed\n");
}

static void NextButton()
{
    // TODO: Implement control logic
}

static void PrevButton()
{
    // TODO: Implement control logic
}

static void LoopButton()
{
    LoopEnabledChecked = !LoopEnabledChecked;
    printf(LoopEnabledChecked ? "Loop Enabled\n" : "Loop Disabled\n");
}

static void ShuffleButton()
{
    ShuffleEnabledChecked = !ShuffleEnabledChecked;
    printf(ShuffleEnabledChecked ? "Shuffle Enabled\n" : "Shuffle Disabled\n");
}

static void MenuButton()
{
    // GUHHHH   
}