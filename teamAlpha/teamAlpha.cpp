#include <raylib.h>
using namespace std;

int main()
{
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);              
    
    while (!WindowShouldClose())    
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
       
    }
    
    CloseWindow();
    return 0;
}