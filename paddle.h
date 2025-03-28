#pragma once

#include "raylib.h"


class Paddle
{
private :
   
    float const mSpeed ;
    float const mBlockZone;

public :
    Paddle();
    Paddle(float posX, int keyUP, int keyDown); 
    float const mHeight;
    float const mWidth ;
    float mPosX ;
    float mPosY ;
    void paddleMove(int screenHeight, int keyPressed);
    void drawPaddle();
    int const mKeyUp;
    int const mKeyDown;
    
};

