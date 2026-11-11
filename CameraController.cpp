 #include "CameraController.h"
#include "Player.h"
using namespace KamataEngine;

void CameraController::Initialize() {
	camera_.Initialize();
	// x軸周りに90度回転させて真下を向くようにする
	camera_.rotation_ = {std::numbers::pi_v<float> / 2.0f, 0.0f, 0.0f};
}

void CameraController::Update() { 
	const WorldTransform& targetWT = target_->GetWorldTransform();
	camera_.translation_ = targetOffset_ + targetWT.translation_;
	camera_.UpdateMatrix();
}

void CameraController::Reset() {
	const WorldTransform& targetWT = target_->GetWorldTransform();
	camera_.translation_ = targetOffset_ + targetWT.translation_;
}
