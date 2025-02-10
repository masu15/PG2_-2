#include "Player.h"
#include"Novice.h"
Player::Player()
{
	posX = 640;
	posY = 360;
	radius = 10;
	speed = 10;
	bullet_ = new  Bullet;
}

Player::~Player()
{
	delete bullet_;
}


void Player::SetposY(int y)
{
	posY = y;
}

void Player::Update(char* keys, char* prekeys)
{
	if (keys[DIK_A]) {
		posX -= speed;
	}
	if (keys[DIK_S]) {
		posY += speed;
	}
	if (keys[DIK_D]) {
		posX += speed;
	}
	if (keys[DIK_W]) {
		posY -= speed;
	}
	if (keys[DIK_SPACE] && !prekeys[DIK_SPACE] && bullet_->GetisShot() == 0) {
		bullet_->SetposX(posX);
		bullet_->SetposY(posY);
  		bullet_->SetisShot(1);
	}
	bullet_->Update();
}

void Player::Draw()
{
	Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, BLUE, kFillModeSolid);
	bullet_->Draw();

}
