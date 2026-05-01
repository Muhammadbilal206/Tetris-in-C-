#include "raylib.h"
#include "Color.h"
#include "position.h"
#include "Block.h"
#include "Blocks.h"
#include "Gridformation.h"
#include"cstdlib"
#include <ctime>

const int screenwidth = 600;
const int screenheight = 700;
const int size = 30;
const int offsetX = 250;
const int offsetY = 50;
int main();
void Gameover();
int countdown();

Color TRANS = { 0,0,0,0 };
Color darkblue={0,9,43,255};

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
    float x, y;
    float w, l;

    void Draw()override
    {
        DrawRectangle(x, y, w, l, TRANS);
    }

    void Text(Font s)override
    {
        DrawTextEx(s, "Exit", Vector2{ 1200 / 4 - 40, 600 / 4 + 70 }, 25, 3, RED);
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
        DrawRectangle(x, y, w, l, TRANS);
    }

    void Text(Font s)override
    {
        DrawTextEx(s, "Replay", Vector2{ 1200 / 4 - 51, 600 / 4 }, 25, 3, BLACK);
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
        DrawRectangle(1200 / 4 - 69, 600 / 4 - 100, 150, 25, TRANS);

        DrawTextEx(s, "GAME OVER!", Vector2{ 1200 / 4 - 142, 600 / 4 - 135 }, 45, 3, PURPLE);
    }
};

Gamefinish gamefinish;

//Function for Gameover screen
void Gameover()
{
    // Making Window
    InitWindow(1200 / 2, 600 / 2, "GameOver");
    InitAudioDevice();
    SetTargetFPS(60);

    Font title = LoadFont("SamuraiBlast.ttf");
    Sound click = LoadSound("butound.WAV");
    SetSoundVolume(click, 0.5f);

    // Initializing for Easy button

    replaybut.x = 1200 / 4 - 55;
    replaybut.y = 600 / 4;
    replaybut.w = 80;
    replaybut.l = 20;

    // Initializing for Medium button

    exitbut.x = 1200 / 4 - 52;
    exitbut.y = 600 / 4 + 60;
    exitbut.w = 60;
    exitbut.l = 20;

    // Main menu loop

    while (WindowShouldClose() == false)
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
            CloseAudioDevice();
            CloseWindow();
            main();
        }

        bool MouseOverExitButton = CheckCollisionPointRec(GetMousePosition(), Rectangle{ exitbut.x, exitbut.y, exitbut.w, exitbut.l });

        if (MouseOverExitButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(click);
            UnloadFont(title);
            CloseAudioDevice();
            CloseWindow();
        }

        EndDrawing();
    }
    UnloadFont(title);
    UnloadSound(click);
    CloseAudioDevice();
    CloseWindow();
}


int main()
{
    //Making Window
    InitWindow(screenwidth, screenheight, "Tetris");
    InitAudioDevice();
    SetTargetFPS(60);
    srand(time(0));

    Font title = LoadFont("SamuraiBlast.ttf");
    Sound over = LoadSound("Gameover.WAV");
    SetSoundVolume(over, 0.5f);
    Texture back = LoadTexture("Tetrisback.png");

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
    const int duration =3;

    bool gameOver = false;
    bool gamestarted=false;
    
    while (!WindowShouldClose())
    {
        int time = countdown(start, duration);
	    if(time == -1 && !gamestarted)
	    {
		    gamestarted=true;
	    }
        BeginDrawing();

        ClearBackground(darkblue);
        
        if(!gamestarted)
		{
			if(time>0)
			{
				DrawTextEx(title,TextFormat("%d",time),Vector2{screenwidth/2 - 50,screenheight/2 - 50},200,8,WHITE);
			}
			else
			{
				DrawTextEx(title,"GO!",Vector2{screenwidth/2-150,screenheight/2-50},200,8,WHITE);
			}
		}

        else
        {

        DrawTexture(back,1,1,WHITE);

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
            fallDelay = 20 + (level - 1) * 5;
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
            if (IsKeyDown(KEY_DOWN))
            {
                tetromino.Move(0, 1);
                if (!grid.IsBlockValid(tetromino))
                {
                    tetromino.Move(0, -1);
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

            frameCounter++;

            if (frameCounter >= fallDelay)
            {
                tetromino.Move(0, 1);
                if (!grid.IsBlockValid(tetromino))
                {
                    tetromino.Move(0, -1);
                    grid.LockBlocks(tetromino);
                    grid.ClearRows(score,lines);
                    tetromino.CreateTetromino();
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
        DrawTextEx(title, "Score", Vector2{70, 50}, 30, 2, WHITE);
        DrawText(TextFormat("%d",score), 70, 100, 60, RAYWHITE);

        DrawRectangleLines(60, 195, 110, 110, RAYWHITE);
        DrawTextEx(title,"Level", Vector2{75, 200}, 30,2, WHITE);
        DrawText(TextFormat("%d", level), 90, 250, 60, RAYWHITE);

        DrawRectangleLines(60, 345, 110, 110, RAYWHITE);
        DrawTextEx(title,"Lines", Vector2{75, 350}, 30,2, WHITE);
        DrawText(TextFormat("%d", lines), 90, 400, 60, RAYWHITE);

    }
        
        if (gameOver)
        {
            gamestarted=false;
            PlaySound(over);
            CloseAudioDevice();
            CloseWindow();
            Gameover();
        }

        EndDrawing();
    }
    UnloadFont(title);
    UnloadSound(over);
    UnloadTexture(back);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}