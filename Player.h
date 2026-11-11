#pragma once
#include "KamataEngine.h"
#include "Matrix4x4Function.h"
#include "Vector3Function.h"
#include "WorldTransformFunction.h"
#include "AABBFunction.h"
#include <numbers>
#include <algorithm>


class Player {
public:
	// 移動入力
	void PlayerMoveInput();		

	// ワールド座標を取得
	KamataEngine::Vector3 GetWorldPosition() const;

	KamataEngine::WorldTransform& GetWorldTransform() { return worldTransform_; }
	const KamataEngine::Vector3& GetVelocity() { return velocity_; }
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);
	void Update();
	// 描画
	void Draw();

private:
	WorldTransformFunction worldTransformF_;
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* playerModel_ = nullptr;
	// カメラ
	KamataEngine::Camera* camera_ = nullptr;
	// 移動の基礎数値
	KamataEngine::Vector3 velocity_ = {0.0f, 0.0f, 0.0f};
	// 天井と床
	static inline const float kAttenuationLanding_ = 0.1f;

		// キャラクターの当たり判定のサイズ
	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;

	static inline const float kBlank = 0.01f;
};
