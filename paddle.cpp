
#include "Paddle.h"


Paddle::Paddle() :
	mSpeed{ 10 },
	mKeyUp {KEY_UP},
	mKeyDown{KEY_DOWN},
	mBlockZone{60},
	mHeight{200},
	mWidth{100},
	mPosX{0},
	mPosY{0}
{}

Paddle::Paddle(float posX, int keyUp, int keyDown) :
	mSpeed{ 10 },
	mKeyUp{ keyUp },
	mKeyDown{ keyDown },
	mBlockZone{ 60 },
	mHeight{ 200 },
	mWidth{ 100 },
	mPosX{ posX },
	mPosY{ 100 }
{}

void Paddle::paddleMove(int screenHeight, int keyPressed)
{
	if (keyPressed = mKeyUp && mPosY >= 0 + mBlockZone) { mPosY += -mSpeed; }
	if (keyPressed = mKeyDown && mPosY + mHeight <= screenHeight - mBlockZone) { mPosY += mSpeed; }
}

void Paddle::drawPaddle()
{
	DrawRectangle(mPosX, mPosY, mWidth, mHeight, WHITE);
}