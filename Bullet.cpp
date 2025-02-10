#include "Bullet.h"
#include<Novice.h>
Bullet::Bullet()
{
	posX = 640;
	posY = 360;
	speed = 15;
	radius = 10;
	isShot = 0;

}

void Bullet::Setspeed(int x)
{
	speed = x;
}

void Bullet::SetposX(int x)
{
	  posX=x;
}

void Bullet::SetposY(int y)
{
	 posY=y;
}

void Bullet::SetisShot(int x)
{
	isShot = x;
}


void Bullet::Update()
{
	if (isShot == 1) {
		posY -= speed;
	}
	if (posY < 0) {
		isShot = 0;
	}
}

void Bullet::Draw()
{
	if (isShot == 1) {
		Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, RED, kFillModeSolid);
	}
}
