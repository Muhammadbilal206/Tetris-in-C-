#include "raylib.h"
#include "Color.h"
#include "position.h"
#include "Block.h"
#include "Blocks.h"
#include "Gridformation.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>

const int screenwidth = 600;
const int screenheight = 700;
const int size = 30;
const int offsetX = 250;
const int offsetY = 50;
int main();
bool Gameover(Font title, Sound click);
int countdown(int start, int duration);

Color TRANS = { 0, 0, 0, 0 };
Color darkblue = { 0, 9, 43, 255 };

// Helper function to locate assets in root or assets/ folder
const char* GetAssetPath(const char* filename)
{
    static char path[256];
    if (FileExists(filename))
    {
        return filename;
    }
    snprintf(path, sizeof(path), "assets/%s", filename);
    if (FileExists(path))
    {
        return path;
    }
    return filename;
}

//Function for countdown
int countdown(int start, int duration)
{
	int elapsed = (int)GetTime() - start;
	int time = duration - elapsed;

	if(time<0)
	{
		time=-1;
	}

	return time;
}

//Parent class for buttons
class Button
{
public:
    float x, y;
    float w, l;

    virtual void Draw()=0;

    virtual void Text(Font s) = 0;
};

//Child class for Exit button  
class Exitbut:public Button
{
public:
    void Draw()override
    {
        DrawRectangle((int)x, (int)y, (int)w, (int)l, TRANS);
    }

    void Text(Font s)override
    {
        DrawTextEx(s, "Exit", Vector2{ x + 25, y + 4 }, 25, 3, RED);
    }
};
Exitbut exitbut;

//Child class for Replay button
class Replaybut:public Button
{
public:
    float x, y;
    float w, l;

    void Draw()override
    {
        DrawRectangle((int)x, (int)y, (int)w, (int)l, TRANS);
    }

    void Text(Font s)override
    {
        DrawTextEx(s, "Replay", Vector2{ x + 10, y + 4 }, 25, 3, BLACK);
    }
};
Replaybut replaybut;

//Class for Gamefinish Message
class Gamefinish
{
public:
    float x, y;
    float w, l;

    void Draw(Font s)
    {
        DrawRectangle((int)x, (int)y, (int)w, (int)l, TRANS);
        DrawTextEx(s, "GAME OVER!", Vector2{ x, y }, 45, 3, PURPLE);
    }
};

Gamefinish gamefinish;

//Function for Gameover screen
bool Gameover(Font title, Sound click)
{
    // Initializing for Gamefinish Message
    gamefinish.x = screenwidth / 2.0f - 142.0f;
    gamefinish.y = screenheight / 2.0f - 120.0f;
    gamefinish.w = 284.0f;
    gamefinish.l = 50.0f;

    // Initializing for Replay button
    replaybut.x = screenwidth / 2.0f - 55.0f;
    replaybut.y = screenheight / 2.0f - 10.0f;
    replaybut.w = 110.0f;
    replaybut.l = 35.0f;

    // Initializing for Exit button
    exitbut.x = screenwidth / 2.0f - 55.0f;
    exitbut.y = screenheight / 2.0f + 55.0f;
    exitbut.w = 110.0f;
    exitbut.l = 35.0f;

    // Main menu loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        gamefinish.Draw(title);

        replaybut.Draw();

        replaybut.Text(title);

        exitbut.Draw();

        exitbut.Text(title);

        bool MouseOverReplayButton = CheckCollisionPointRec(GetMousePosition(), Rectangle{ replaybut.x, replaybut.y, replaybut.w, replaybut.l });

        if (MouseOverReplayButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(click);
            EndDrawing();
            return true;
        }

        bool MouseOverExitButton = CheckCollisionPointRec(GetMousePosition(), Rectangle{ exitbut.x, exitbut.y, exitbut.w, exitbut.l });

        if (MouseOverExitButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(click);
            EndDrawing();
            return false;
        }

        EndDrawing();
    }

    return false;
}


int main()
{
    //Making Window
    InitWindow(screenwidth, screenheight, "Tetris");
    InitAudioDevice();
    SetTargetFPS(60);
    srand((unsigned int)time(0));

    Font title = LoadFont(GetAssetPath("SamuraiBlast.ttf"));
    Sound over = LoadSound(GetAssetPath("Gameover.WAV"));
    Sound click = LoadSound(GetAssetPath("butound.WAV"));
    SetSoundVolume(over, 0.5f);
    SetSoundVolume(click, 0.5f);
    Texture back = LoadTexture(GetAssetPath("Tetrisback.png"));

    bool playAgain = true;

    while (playAgain && !WindowShouldClose())
    {
        //Creating Grid and tetrimino
        Gridformation grid;
        Blocks tetromino;
        tetromino.CreateTetromino();

        //Initializing
        int frameCounter = 0;
        int fallDelay = 20;
        int score = 0;
        int lines = 0;
        int level = 0;
        int start = (int)GetTime();
        const int duration = 3;

        bool gameOver = false;
        bool gamestarted = false;
        bool fastDropLocked = false;

        while (!WindowShouldClose())
        {
            int time = countdown(start, duration);
            if(time == -1 && !gamestarted)
            {
                gamestarted = true;
            }

            BeginDrawing();

            ClearBackground(darkblue);

            if(!gamestarted)
            {
                if(time > 0)
                {
                    DrawTextEx(title, TextFormat("%d", time), Vector2{ screenwidth / 2 - 50, screenheight / 2 - 50 }, 200, 8, WHITE);
                }
                else
                {
                    DrawTextEx(title, "GO!", Vector2{ screenwidth / 2 - 150, screenheight / 2 - 50 }, 200, 8, WHITE);
                }
            }
            else
            {
                DrawTexture(back, 1, 1, WHITE);

                //logic for level and lines
                level = (lines / 10) + 1;
                if (level > 8)
                {
                    level = 1;
                    fallDelay = 20;
                    lines = 0;
                }
                else
                {
                    fallDelay = 20 - (level - 1) * 2;
                    if (fallDelay < 4) fallDelay = 4;
                }

                //movement of tetrimino
                if (!gameOver)
                {
                    if (IsKeyPressed(KEY_LEFT))
                    {
                        tetromino.Move(-1, 0);
                        if (!grid.IsBlockValid(tetromino))
                        {
                            tetromino.Move(1, 0);
                        }
                    }
                    if (IsKeyPressed(KEY_RIGHT))
                    {
                        tetromino.Move(1, 0);
                        if (!grid.IsBlockValid(tetromino))
                        {
                            tetromino.Move(-1, 0);
                        }
                    }
                    if (IsKeyPressed(KEY_UP))
                    {
                        tetromino.Rotate();
                        if (!grid.IsBlockValid(tetromino))
                        {
                            for (int i = 0; i < 3; i++)
                            {
                                tetromino.Rotate();
                            }
                        }
                    }

                    // Reset soft drop lock when DOWN key is released
                    if (!IsKeyDown(KEY_DOWN))
                    {
                        fastDropLocked = false;
                    }

                    // Fast drop while holding DOWN
                    int currentDelay = fallDelay;
                    if (IsKeyDown(KEY_DOWN) && !fastDropLocked)
                    {
                        currentDelay = 2;
                    }

                    frameCounter++;

                    if (frameCounter >= currentDelay)
                    {
                        tetromino.Move(0, 1);
                        if (!grid.IsBlockValid(tetromino))
                        {
                            tetromino.Move(0, -1);
                            grid.LockBlocks(tetromino);
                            grid.ClearRows(score, lines);
                            tetromino.CreateTetromino();
                            fastDropLocked = true; // Prevent new piece from instantly shooting down if DOWN is still held
                            if (!grid.IsBlockValid(tetromino))
                            {
                                gameOver = true;
                            }
                        }
                        frameCounter = 0;
                    }
                }

                grid.Draw(size, offsetX, offsetY);

                if (!gameOver)
                {
                    tetromino.Draw(size, offsetX, offsetY);
                }

                DrawRectangleLines(60, 45, 110, 110, RAYWHITE);
                DrawTextEx(title, "Score", Vector2{ 70, 50 }, 30, 2, WHITE);
                DrawText(TextFormat("%d", score), 70, 100, 60, RAYWHITE);

                DrawRectangleLines(60, 195, 110, 110, RAYWHITE);
                DrawTextEx(title, "Level", Vector2{ 75, 200 }, 30, 2, WHITE);
                DrawText(TextFormat("%d", level), 90, 250, 60, RAYWHITE);

                DrawRectangleLines(60, 345, 110, 110, RAYWHITE);
                DrawTextEx(title, "Lines", Vector2{ 75, 350 }, 30, 2, WHITE);
                DrawText(TextFormat("%d", lines), 90, 400, 60, RAYWHITE);
            }

            EndDrawing();

            if (gameOver)
            {
                PlaySound(over);
                playAgain = Gameover(title, click);
                break;
            }
        }

        if (WindowShouldClose())
        {
            playAgain = false;
        }
    }

    UnloadFont(title);
    UnloadSound(over);
    UnloadSound(click);
    UnloadTexture(back);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
