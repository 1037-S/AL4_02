#include "NormalEnemy.h"
#include "Player.h"

using namespace KamataEngine;

void NormalEnemy::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) {

// NULLポインタチェック
#ifdef _DEBUG
	assert(model);
	assert(camera);
#endif // _DEBUG

	model_ = model;
	camera_ = camera;

	worldTransformF_.WorldTransformInitialize(worldTransform_);
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	MAXHP_ = 10;
	HP_ = MAXHP_;
	ATK_ = 5;
	DEF_ = 5;
	moveSpeed_ = 0.08f;
}

void NormalEnemy::Update() {
	if (target_) {
		// 1. プレイヤーと自身の座標を取得（XZ平面で計算）
		const Vector3& playerPos = target_->GetWorldTransform().translation_;
		Vector3& enemyPos = worldTransform_.translation_;

		Vector2 diff{playerPos.x - enemyPos.x, playerPos.z - enemyPos.z};

		// 2. 既存の Vector2F_.Length で距離を計算
		float distance = Vector2F_.Length(diff);

		// 3. ゼロ除算防止 ＆ 重なりすぎ防止（少し手前で止める場合は 0.5f などに調整）
		if (distance > 0.01f) {
			// 正規化（長さ1の方向ベクトルにする）
			float dirX = diff.x / distance;
			float dirZ = diff.y / distance; // Vector2 の y に Z成分を入れているため

			// 移動量を加算
			enemyPos.x += dirX * moveSpeed_;
			enemyPos.z += dirZ * moveSpeed_;

			// プレイヤーの方向を向く（Y軸回転）
			worldTransform_.rotation_.y = std::atan2(dirX, dirZ);
		}
	}
	worldTransformF_.WorldTransformUpdate(worldTransform_);
}

void NormalEnemy::Draw() {
	if (model_ && camera_) {
		model_->Draw(worldTransform_, *camera_);
	}
}
