#pragma once
#include "KamataEngine.h"
#include "Matrix4x4Function.h"
#include "Vector3Function.h"
#include "WorldTransformFunction.h"
#include "AABBFunction.h"
#include "Player.h"
#include "NormalEnemy.h"
#include "Skydome.h"
#include "CameraController.h"
#include <vector>

class GameScene {
public:
	~GameScene();

	// プレイフェーズの処理
	void PlayPhase();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// 数学関数
	Matrix4x4Function matrix4x4_;
	Vector3Function vector3_;
	WorldTransformFunction worldTransformF_;
	AABBFunction aabb_;

	
	// ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;

	// 自キャラ
	Player* player_ = nullptr;
	KamataEngine::Vector3 playerInitialPosition_;
	KamataEngine::Model* playerModel_ = nullptr;
	Skydome* skydome_ = nullptr;

	// 敵キャラ
	NormalEnemy* enemy_ = nullptr;
	KamataEngine::Model* enemyModel_ = nullptr;

	// カメラコントローラー
	CameraController* cameraController_ = nullptr;

	// ブロック用
	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;

	KamataEngine::Model* blockModel_ = nullptr;

		// テクスチャハンドル
	uint32_t textureHandle_ = 0;
};
