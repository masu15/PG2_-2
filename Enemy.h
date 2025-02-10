#pragma once
class Enemy
{
private:
	int posX;
	int posY;
	int speedX;
	int radiusX;
	int radiusY;
	static int flag;
	int timer;
public:
	int GetposX() { return posX; }
	int GetPosY() { return posY; }
	void SetposX(int x);
	void SetPosY(int y);
	int Getradius() { return radiusX; }
	void Setflag(int x);
	int Getflag() { return flag; }
	Enemy(int x, int y);
	//敵の更新処理
	void Update();
	//敵の描画処理
	void Draw();

};

