#include "raylib.h"
#include <iostream>

using namespace std;


Color changeColor() 
{
    unsigned char r = (rand() % 255) + 1;
    unsigned char g = (rand() % 255) + 1;
    unsigned char b = (rand() % 255) + 1;
  
 return Color{r,g,b,255 };;
}

int main() {

    
    cout << "Hello World" << endl;
    int screenWidth = 600;
    int screenHeight = 200;
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Marie's first Raylib window!");
    SetTargetFPS(60);
    //INIT
    float directionX = 1;
    float directionY = 1;
    float ballX = 200;
    float ballY = 50;
    float radius = 20;
    Color color = DARKGREEN;
    Font font = LoadFont("ressources/fonts/alagard.png");
   
    
    

    while (!WindowShouldClose()) {
        //UPDATE
        ballX += 2 * directionX;
        ballY += 1 * directionY;
        Vector2 ballV{ ballX, ballY };

        
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        //DRAW
        if (ballX >= screenWidth - radius || ballX <= 0 + radius) { directionX *= -1; color = changeColor(); DrawTextEx(font, "This is a hospital", ballV, 25, 1, RED);}
        if (ballY >= screenHeight - radius || ballY <= 0 + radius) { directionY *= -1; color = changeColor(); DrawTextEx(font, "This is a hospital", ballV, 25, 1, RED);}
        DrawCircle(ballX, ballY, radius, color);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}