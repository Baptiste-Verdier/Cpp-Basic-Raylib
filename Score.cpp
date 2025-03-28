
#include "Score.h"
#include "Ball.h"
#include "raylib.h"
Score::Score() :
	mValue {0},
	mGoal{0},
	mPosX{0},
	mPosY{0},
	mPlace{ mPosX, mPosY },
	mFont{LoadFont("resources/fonts/alagard.png")}
{}

Score::Score(float goal, float posX) :
	mValue{ 0 },
	mGoal{ goal },
	mPosX{ posX },
	mPosY{ 0 },
	mPlace{mPosX, mPosY},
	mFont{ LoadFont("resources/fonts/alagard.png") }
{}

void Score::scoreIncrease(Ball* ball)
{
	mValue++;
	ball->mPosX = 0;
	ball->mPosY = 0;
	ball->mSpeed = ball->mBaseSpeed;

}

void Score::drawText()
{
	DrawTextEx(mFont, TextFormat("%i", mValue), mPlace , 100, 1, WHITE);
}



