#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	
	delete player_;
	delete blockModel_;
	delete enemy_;      
	delete enemyModel_; 
	delete playerModel_;
	delete cameraController_;
}

void GameScene::PlayPhase() {}

void GameScene::Initialize() {
	
	// カメラの生成と初期化
	cameraController_ = new CameraController();
	cameraController_->Initialize();

	// ファイル名を指定してテクスチャを読み込む(3Dモデル)
	blockModel_ = Model::CreateFromOBJ("block", true);
	worldTransform_.Initialize();
	worldTransform_.translation_ = {0.0f, -1.0f, 5.0f};
	
	playerModel_ = Model::CreateFromOBJ("player", true);
	// プレイヤーの生成と初期化

	player_ = new Player();
	player_->Initialize(playerModel_, cameraController_->GetCameraPtr(), playerInitialPosition_);

	enemyModel_ = Model::CreateFromOBJ("enemy", true);
	// 雑魚敵の生成と初期化
	enemy_ = new NormalEnemy();
	enemy_->Initialize(enemyModel_, cameraController_->GetCameraPtr(), {0.0f, 0.0f, 15.0f});

	// 追尾対象としてプレイヤーをセット
	enemy_->SetTarget(player_);


	//カメラに追従対象（プレイヤー）をセットして初期位置へ合わせる
	cameraController_->SetTarget(player_);
	cameraController_->Reset();
}

void GameScene::Update() {

	// プレイヤーの更新
	
	player_->Update();

	if (enemy_) {
		enemy_->Update();
	}

	// カメラの更新（プレイヤーの位置に追従して行列を更新）
	cameraController_->Update();
}

void GameScene::Draw() { 
	Model::PreDraw();

	// 3Dモデルを描画
	blockModel_->Draw(worldTransform_, *cameraController_->GetCameraPtr());
	player_->Draw();

	if (enemy_) {
		enemy_->Draw();
	}


	Model::PostDraw();

}
