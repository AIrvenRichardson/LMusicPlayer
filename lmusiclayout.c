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

#define SUPPORT_FILEFORMAT_FLAC 1// Enable FLAC audio format support
#undef RAYGUI_IMPLEMENTATION // Avoids multiple implementation compilation issues
#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "gui_window_file_dialog.h"

// Controls Functions Declaration
static void PauseButton();
static void NextButton();
static void PrevButton();
static void MenuButton();
static void LoopButton();
static void ShuffleButton();

// Global Controls Variables Declaration
bool ShuffleEnabledChecked = false;
bool LoopEnabledChecked = false;
bool Paused = false;

int main()
{
    // Initialization
    int screenWidthDefault = 410, screenHeightDefault = 450;

    SetConfigFlags(FLAG_BORDERLESS_WINDOWED_MODE);
    InitWindow(screenWidthDefault, screenHeightDefault, "Music Player");

    // lmusiclayout: controls initialization
    bool LMusicPlayerActive = true;
    float VolumeSliderValue = 100.0f;

    // Gui file dialog initialization
    GuiWindowFileDialogState fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());
    char fileNameToLoad[1024] = { 0 };
    int dialogWidth = 440, dialogHeight = 310;
    fileDialogState.windowBounds = (Rectangle){ 0, 0, dialogWidth, dialogHeight };

    // Music Initialization
    InitAudioDevice();
    Music music = {0};
    float timePlayed = 0.0f;


    SetTargetFPS(60);
    GuiLoadStyle("style_cyber.rgs"); // Load raygui style file

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        if (!Paused)
        {
            UpdateMusicStream(music);
            timePlayed = GetMusicTimePlayed(music);
            SetMusicVolume(music, VolumeSliderValue/100.0f);
        }

        if (fileDialogState.SelectFilePressed)
        {
            if (IsFileExtension(fileDialogState.fileNameText, ".mp3") 
            || IsFileExtension(fileDialogState.fileNameText, ".flac") //TODO: Need to compile raylib with FLAC support
            || IsFileExtension(fileDialogState.fileNameText, ".wav"))
            {
                strcpy(fileNameToLoad, TextFormat("%s/%s", fileDialogState.dirPathText, fileDialogState.fileNameText));
                // Load music from file
                music = LoadMusicStream(fileNameToLoad);
                printf("Loaded file: %s\n", fileNameToLoad);
                PlayMusicStream(music);
                Paused = false;
            }
            fileDialogState.SelectFilePressed = false;
        }

        // Draw
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            if (fileDialogState.windowActive) {
                SetWindowSize(dialogWidth, dialogHeight);
                GuiLock();
            } else {
                SetWindowSize(screenWidthDefault, screenHeightDefault);
            }

            if (LMusicPlayerActive)
            {
                GuiLabel((Rectangle){ 25, 20, 120, 24 }, "Now Playing: X");
                if (GuiButton((Rectangle){ screenWidthDefault/2-12, screenHeightDefault-30, 24, 24 }, "#132#")) PauseButton(); 
                if (GuiButton((Rectangle){ screenWidthDefault/2+36, screenHeightDefault-30, 24, 24 }, "#134#")) NextButton(); 
                if (GuiButton((Rectangle){ screenWidthDefault/2-60, screenHeightDefault-30, 24, 24 }, "#129#")) PrevButton(); 
                if (GuiButton((Rectangle){ 25, screenHeightDefault-30, 24, 24 }, "#78#")) ShuffleButton(); 
                if (GuiButton((Rectangle){ screenWidthDefault-48, screenHeightDefault-30, 24, 24 }, "#74#")) LoopButton(); 
                if (GuiButton((Rectangle){ 0, 0, 24, 24 }, "#141#")) fileDialogState.windowActive = true;
                GuiSliderBar((Rectangle){ screenWidthDefault-145, 20, 120, 16 }, NULL, NULL, &VolumeSliderValue, 0, 100);
                GuiLabel((Rectangle){ screenWidthDefault-170, 20, 112, 16 }, "Vol:");
                GuiPanel((Rectangle){ 25, 50, 360, 360 }, NULL);
            }

            GuiUnlock();
            GuiWindowFileDialog(&fileDialogState);

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}

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