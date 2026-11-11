#pragma once
#include "KamataEngine.h"
#include <numbers>

class Player;

class CameraController {
public:
	void Initialize();
	void Update();
	void Reset();

	void SetTarget(Player* target) { target_ = target; }

private:
	KamataEngine::Camera camera_ ;
	Player* target_ = nullptr;
	KamataEngine::Vector3 targetOffset_ = {0.0f, 30.0f, 0.0f};
};
