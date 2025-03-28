#include "raylib.h"
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"

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
    float screenWidth = 1000;
    float screenHeight = 600;
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Marie's first Raylib window!");
    SetTargetFPS(60);
    //INIT
  
    Image img = LoadImage("resources/images/stp_bg.png");
    Image* imgPtr = &img;
    Texture2D texture = LoadTextureFromImage(img);
   
    InitAudioDevice();
    Music music = LoadMusicStream("resources/musics/ironlegion.mp3");
    PlayMusicStream(music);

   // UnloadImage(img);

    Paddle player1(100, KEY_UP, KEY_DOWN);
    Paddle* player1Ptr = &player1;
    Paddle player2(screenWidth - 100, KEY_W, KEY_S);
    Paddle* player2Ptr = &player2;
    Ball ball;
    Ball* ballPtr = &ball;
    Score scorePlayer1(0, screenWidth - 100);
    Score scorePlayer2(screenWidth,  100);
   

    while (!WindowShouldClose()) {
        //UPDATE
        UpdateMusicStream(music);
        ball.ballMove();
        ball.collision(player1Ptr);
        ball.collision(player2Ptr);
        if (ball.mPosX >= screenWidth - ball.mRadius) { scorePlayer2.scoreIncrease(ballPtr); }
        if (ball.mPosY <= 0 + ball.mRadius) { scorePlayer1.scoreIncrease(ballPtr); }


        
        if (IsKeyDown(player1.mKeyUp) || IsKeyDown(player1.mKeyDown) ) { player1.paddleMove(screenHeight, GetKeyPressed());}
        if (IsKeyDown(player2.mKeyUp) || IsKeyDown(player2.mKeyDown)) { player2.paddleMove(screenHeight, GetKeyPressed()); }

        BeginDrawing();
        
        ClearBackground(DARKGREEN);
        //DRAW
       
        DrawTexture( texture,  0,  0, WHITE);
        ball.drawBall();
        player1.drawPaddle();
        player2.drawPaddle();
        scorePlayer1.drawText();
        scorePlayer2.drawText();
        
        EndDrawing();
    }

    UnloadMusicStream(music);

    CloseWindow();
    return 0;
}