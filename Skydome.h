#pragma once
#include "KamataEngine.h"
class Skydome {
public:
	// Skydome();
	~Skydome();

	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera);
	
	void Draw();

private:
	// ワールド変換
	KamataEngine::WorldTransform worldTransform_;
	// カメラ
	KamataEngine::Camera* camera_ = nullptr;
	// モデル
	KamataEngine::Model* model_ = nullptr;
};
