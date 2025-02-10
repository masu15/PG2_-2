#include "Enemy.h"
#include"Novice.h"

void Enemy::Setflag(int x)
{
	  flag=x;
}
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	speedX = 10;
	radiusX = 20;
	radiusY = 20;
	flag = 1;
	timer = 60;
}

void Enemy::Update()
{
	posX += speedX;
	if (posX - radiusX < 0) {
		speedX *= -1;
	}
	if (posX + radiusX > 1280) {
		speedX *= -1;
	}

}

void Enemy::Draw()
{
	if (flag == 1) {
		Novice::DrawEllipse(posX, posY, radiusX, radiusY, 0.0f, RED, kFillModeSolid);
	}
}