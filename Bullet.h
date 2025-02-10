#pragma once
class Bullet
{
private:
	int posX;
	int posY;
	int speed;
	int radius;
	int isShot;
public:
	int GetposX() { return posX; }
	int GetposY() { return posY; }
	void Setspeed(int x);
	int Getradius() { return radius; }
	void SetposX(int x);
	void SetposY(int y);
	void SetisShot(int x);
	int GetisShot() { return isShot; }
	//弾の更新処理
	void Update();
	//弾の描画処理
	void Draw();
	Bullet();

};

