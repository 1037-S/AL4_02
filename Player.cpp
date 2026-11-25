#define NOMINMAX
#include "Player.h"
#include <cmath>

using namespace KamataEngine;

void Player::PlayerMoveInput() {
	Vector3 move = {0.0f, 0.0f, 0.0f};
	Input* input = Input::GetInstance();
	if (input->PushKey(DIK_W) || input->PushKey(DIK_UP)) {
		move.z += 1.0f; // 奥へ
	}
	if (input->PushKey(DIK_S) || input->PushKey(DIK_DOWN)) {
		move.z -= 1.0f; // 手前へ
	}
	if (input->PushKey(DIK_A) || input->PushKey(DIK_LEFT)) {
		move.x -= 1.0f; // 左へ
	}
	if (input->PushKey(DIK_D) || input->PushKey(DIK_RIGHT)) {
		move.x += 1.0f; // 右へ
	}

	// 入力がある場合のみ計算する
	float length = std::sqrt(move.x * move.x + move.z * move.z);
	if (length > 0.0f) {
		// 1. 斜め移動が速くならないように正規化（長さを1にする）
		move.x /= length;
		move.z /= length;

		// 2. 速度を掛けて移動量(velocity_)を決定
		velocity_.x = move.x * moveSpeed_;
		velocity_.z = move.z * moveSpeed_;

		// 3. 進行方向にプレイヤーの向き（Y軸回転）を合わせる
		// モデルが +Z 方向を正面としている場合の角度計算
		worldTransform_.rotation_.y = std::atan2(move.x, move.z);
	} else {
		// 入力がない場合は停止
		velocity_ = {0.0f, 0.0f, 0.0f};
	}
}

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) { // NULLポインタチェック
#ifdef _DEBUG
	assert(model);
	assert(camera);
#endif // _DEBUG
	model_ = model;
	// playerModelAttack_ = modelAttack;
	camera_ = camera;
	// ワールド変換の初期化
	worldTransformF_.WorldTransformInitialize(worldTransform_);
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	moveSpeed_ = kMoveSpeed_;
	width_ = kWidth;
	height_ = kHeight;
	MAXHP_ = 100;
	HP_ = MAXHP_;
	ATK_ = 10;
	DEF_ = 5;
}

void Player::Update() {
	PlayerMoveInput();

	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;

	worldTransformF_.WorldTransformUpdate(worldTransform_);
}

void Player::Draw() {
	// 3Dモデルを描画する
	model_->Draw(worldTransform_, *camera_);
}
