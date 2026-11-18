 #include "CameraController.h"
#include "Player.h"
using namespace KamataEngine;

void CameraController::Initialize() {
	camera_.Initialize();
	// x軸周りに調整
	camera_.rotation_ = {std::atan2(targetOffset_.y,-targetOffset_.z), 0.0f, 0.0f};

}

void CameraController::Update() { 
	const WorldTransform& targetWT = target_->GetWorldTransform();
	destination_ = targetOffset_ + targetWT.translation_;
	camera_.translation_ = lerpF_.Lerp(camera_.translation_,destination_,
		kInterpoolationRate);
	camera_.UpdateMatrix();
}

void CameraController::Reset() {
	const WorldTransform& targetWT = target_->GetWorldTransform();
	destination_ = targetOffset_ + targetWT.translation_;
	camera_.translation_ = destination_;
	

}
