#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
const char kWindowTitle[] = "GC1D_07_マスヤマ_リョウタ_タイトル";

const int kWindowWidte = 1280;
const int kWindowHaight = 720;
int Enemy::flag;
int scene = 0;
int a;
int b;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidte, kWindowHaight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	Player* player = new Player();
	Enemy* enemy[2];
	enemy[0] = new Enemy(30, 50);
	enemy[1] = new Enemy(60, 150);
	a = Novice::LoadTexture("./title.png");
	b = Novice::LoadTexture("./clear.png");
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene)
		{
		case 0:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = 1;
			}
			break;
		case 1:

			player->Update(keys, preKeys);
			for (int i = 0; i < 2; i++) {
				enemy[i]->Update();
					//敵と弾の当たり判定
					float distX = (float)enemy[i]->GetposX() - (float)player->bullet_->GetposX();
					float distY = (float)enemy[i]->GetPosY() - (float)player->bullet_->GetposY();
					float dist = (distX * distX) + (distY * distY);
 					int radius = enemy[i]->Getradius() + player->bullet_->Getradius();

					if (dist <= radius * radius) {


						enemy[i]->Setflag(0);
						player->SetposY(500);
						player->bullet_->SetposY(-100);
					}
				//敵とプレイヤーの当たり判定
				float distA = (float)enemy[i]->GetposX() - (float)player->GetPosX();
				float distB = (float)enemy[i]->GetPosY() - (float)player->GetPosY();
				float distC = (distA * distA) + (distB * distB);
				int radius1 = enemy[i]->Getradius() + player->Getradius();
				if (distC <= radius1 * radius1) {

					enemy[i]->Setflag(0);
					player->SetposY(500);
				}


				if (enemy[i]->Getflag() == false) {
					scene = 2;
				}
			}break;
		case 2:
			for (int i = 0; i < 2; i++) {
				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					scene = 0;
					enemy[i]->Setflag(1);
					player->bullet_->SetisShot(player->bullet_->GetisShot() == 0);
				}
			}
		}



		///
		/// ↑更新処理ここまで
		///


		///
		/// ↓描画処理ここから

		switch (scene)
		{
		case 0:
			Novice::DrawSprite(0, 0, a, 1, 1, 0.0f, WHITE);
			break;
		case 1:
			player->Draw();
			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}break;
		case 2:
			Novice::DrawSprite(0, 0, b, 1, 1, 0.0f, WHITE);
		}

		/// 
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
