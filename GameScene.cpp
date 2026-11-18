#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	
	delete player_;
	delete blockModel_;
}

void GameScene::PlayPhase() {}

void GameScene::Initialize() {
	
	// 1. カメラの生成と初期化
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


	//カメラに追従対象（プレイヤー）をセットして初期位置へ合わせる
	cameraController_->SetTarget(player_);
	cameraController_->Reset();
}

void GameScene::Update() {

	// プレイヤーの更新
	
	player_->Update();

	// カメラの更新（プレイヤーの位置に追従して行列を更新）
	cameraController_->Update();
}

void GameScene::Draw() { 
	Model::PreDraw();

	// 3Dモデルを描画
	blockModel_->Draw(worldTransform_, *cameraController_->GetCameraPtr());
	player_->Draw();


	Model::PostDraw();

}
