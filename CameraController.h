#pragma once
#include "KamataEngine.h"
#include "LerpFunction.h"
#include <numbers>

class Player;

class CameraController {
public:
	void Initialize();
	void Update();
	void Reset();

	void SetTarget(Player* target) { target_ = target; }


	const KamataEngine::Camera& GetCamera() const { return camera_; }
	KamataEngine::Camera* GetCameraPtr() { return &camera_; }

private:
	LerpFunction lerpF_;
	KamataEngine::Camera camera_ ;
	Player* target_ = nullptr;
	KamataEngine::Vector3 targetOffset_ = {0.0f, 20.0f, -15.0f};
	KamataEngine::Vector3 destination_{};
	static inline const float kInterpoolationRate = 0.1f;

};
