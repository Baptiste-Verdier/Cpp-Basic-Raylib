#pragma once
#include "raylib.h"
class Paddle;

class Ball
{
private:
	Vector2 mDirection;
	
	float const mMaxSpeed;

public:
	Ball();
	float const mRadius;
	float const mBaseSpeed;
	float mSpeed;
	float mPosX;
	float mPosY;
	void collision(Paddle* paddle);
	void drawBall();
	void ballMove();
};

