#pragma once
#include "raylib.h"

class Ball;

class Score
{
	
public :
	Score();
	Score(float goal, float posX);
	
	void scoreIncrease(Ball* ball);
	void drawText();

private :
	float mValue;
	float const mGoal;
	float const mPosX;
	float const mPosY;
	Vector2 const mPlace;
	Font mFont;
};

