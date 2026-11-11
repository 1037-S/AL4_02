#define NOMINMAX
#include "Player.h"

using namespace KamataEngine;

void Player::PlayerMoveInput() {}

KamataEngine::Vector3 Player::GetWorldPosition() const {
	Vector3 worldPos;

	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) { // NULLポインタチェック
#ifdef _DEBUG
	assert(model);
	assert(camera);
#endif // _DEBUG
	playerModel_ = model;
	//playerModelAttack_ = modelAttack;
	camera_ = camera;
	// ワールド変換の初期化
	worldTransformF_.WorldTransformInitialize(worldTransform_);
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
}

void Player::Update() { worldTransformF_.WorldTransformUpdate(worldTransform_); }

void Player::Draw() {// 3Dモデルを描画する
	playerModel_->Draw(worldTransform_, *camera_);
}
