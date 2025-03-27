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
Font changeFont()
{
    Font font;
    int random = (rand() % 8) + 1;
    switch (random) 
    {
    case 1:
        font = LoadFont("resources/fonts/alagard.png");
        break;
    case 2:
        font = LoadFont("resources/fonts/alpha_beta.png");
        break;
    case 3:
        font = LoadFont("resources/fonts/jupiter_crash.png");
        break;
    case 4:
        font = LoadFont("resources/fonts/mecha.png");
        break;
    case 5:
        font = LoadFont("resources/fonts/pixantiqua.png");
        break;
    case 6:
        font = LoadFont("resources/fonts/pixelplay.png");
        break;
    case 7:
        font = LoadFont("resources/fonts/romulus.png");
        break;
    case 8:
        font = LoadFont("resources/fonts/setback.png");
        break;
    }

    return font;
}

int main() {

    
    cout << "Hello World" << endl;
    int screenWidth = 1000;
    int screenHeight = 600;
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Marie's first Raylib window!");
    SetTargetFPS(60);
    //INIT
    float directionX = 1;
    float directionY = 1;
    float ballX = 200;
    float ballY = 50;
    float radius = 20;
    Font ft = changeFont();
    Color color = DARKGREEN;
    float paddlePositionX = 100;
    float paddlePositionY1 = 300;
    float paddlePositionY2 = 300;
    int paddleHeight = 200;
    int paddleWidth = 20;
    int paddleSpeed = 10;
    int ballSpeed = 10;
    int score1 = 0;
    int score2 = 0;
    int blockPaddleZone = 75;
    Vector2 placeScore1{ screenWidth/2 - 100, 50 };
    Vector2 placeScore2{ screenWidth /2 + 100, 50 };
    Image img = LoadImage("resources/images/stp_bg.png");
    Image* imgPtr = &img;
    Texture2D texture = LoadTextureFromImage(img);
   
    InitAudioDevice();
    Music music = LoadMusicStream("resources/musics/ironlegion.mp3");
    PlayMusicStream(music);

   // UnloadImage(img);



    while (!WindowShouldClose()) {
        //UPDATE
        UpdateMusicStream(music);
        ballX += ballSpeed * directionX;
        ballY += ballSpeed/2 * directionY;
      
        
        if (ballX >= paddlePositionX - radius && ballX <= paddlePositionX + paddleWidth + radius) 
        {
            if (ballY >= paddlePositionY1 - radius && ballY <= paddlePositionY1 + paddleHeight + radius)
            {
                directionX *= -1; color = changeColor(); changeFont();
                ballSpeed++;
            }
        }
        if (ballX >= screenWidth - paddlePositionX - radius &&  ballX <= screenWidth - paddlePositionX + paddleWidth + radius)
        {
            if (ballY >= paddlePositionY2 - radius && ballY <= paddlePositionY2 + paddleHeight + radius)
            {
                directionX *= -1; color = changeColor(); changeFont();
                ballSpeed++;
            }
        }

        if (ballY >= screenHeight - radius || ballY <= 0 + radius) { directionY *= -1; color = changeColor(); changeFont(); }
        if (ballX >= screenWidth - radius) { ballX = screenWidth / 2; ballY = screenHeight / 2; changeFont(); score1++; }
        if (ballX <= 0 + radius) { ballX = screenHeight / 2; ballY = screenWidth / 2; changeFont(); score2++; }
        
        if (IsKeyDown(KEY_UP) && paddlePositionY1 >= 0 + blockPaddleZone ) { paddlePositionY1 += -paddleSpeed; }
        if (IsKeyDown(KEY_DOWN) && paddlePositionY1 + paddleHeight <= screenHeight - blockPaddleZone) { paddlePositionY1 += paddleSpeed; }
        if (IsKeyDown(KEY_W) && paddlePositionY2 >= 0 + blockPaddleZone) { paddlePositionY2 += -paddleSpeed; }
        if (IsKeyDown(KEY_S) && paddlePositionY2 + paddleHeight <= screenHeight - blockPaddleZone) { paddlePositionY2 += paddleSpeed; }

        BeginDrawing();
        
        ClearBackground(DARKGREEN);
        //DRAW
       
        DrawTexture( texture,  0,  0, WHITE);
        DrawCircle(ballX, ballY, radius, WHITE);
        DrawRectangle(paddlePositionX, paddlePositionY1, paddleWidth, paddleHeight, WHITE);
        DrawRectangle(screenWidth-paddlePositionX, paddlePositionY2, paddleWidth, paddleHeight, WHITE);
        DrawRectangle(screenWidth / 2 + 10, 0, 10, screenHeight, WHITE);
        DrawTextEx(ft, TextFormat("%i", score1), placeScore1, 100, 1, WHITE);
        DrawTextEx(ft, TextFormat("%i", score2), placeScore2, 100, 1, WHITE);
        EndDrawing();
    }

    UnloadMusicStream(music);

    CloseWindow();
    return 0;
}