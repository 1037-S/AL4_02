#pragma once
#include "KamataEngine.h"
#include "Matrix4x4Function.h"
#include "Vector3Function.h"
#include "WorldTransformFunction.h"
#include "AABBFunction.h"
#include "Player.h"
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

	// 自キャラ
	Player* player_ = nullptr;
	KamataEngine::Vector3 playerInitialPosition_;
	KamataEngine::Model* playerModel_ = nullptr;
	Skydome* skydome_ = nullptr;

	// ブロック用
	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;
};
