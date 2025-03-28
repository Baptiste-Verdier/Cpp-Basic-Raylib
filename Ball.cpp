
#include "Ball.h"
#include "Paddle.h"
#include "vector"

Ball::Ball() :
	mBaseSpeed{ 1 },
	mPosX{ 300 },
	mPosY{100},
	mDirection{-1,1},
	mRadius{50},
	mMaxSpeed{75}
{mSpeed = mBaseSpeed;}

void Ball::collision(Paddle* paddle) 
{
	if (mPosY >= paddle->mPosX + paddle->mWidth - mRadius && mPosX >= paddle->mPosY + paddle->mHeight - mRadius)
	{
		if (mPosY <= paddle->mPosX - mRadius && mPosX <= paddle->mPosY - mRadius)
		{
			mDirection.x *= -1;
			if (mSpeed <= mMaxSpeed) { mSpeed++; }
		}
	}
}

void Ball::drawBall()
{
	DrawCircle(mPosX, mPosY, mRadius, WHITE);
}

void Ball::ballMove() 
{
	mPosX += mSpeed * mDirection.x;
	mPosY += mSpeed / 2 * mDirection.y;
}