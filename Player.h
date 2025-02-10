#pragma once
#include"Bullet.h"
class Player
{
public:
	Player();
	~Player();


	int posX;
	int posY;
	int radius;
	int speed;
public:
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }
	int Getradius() { return radius; }
	int Getspeed() { return speed; }
	void SetposY(int y);
	Bullet* bullet_;
	//プレイヤーの更新処理
	void Update(char* keys, char* prekeys);
	//プレイヤーの描画処理
	void Draw();

};


