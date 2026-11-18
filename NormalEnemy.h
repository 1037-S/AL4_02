#pragma once
#include "Enemy.h"
class NormalEnemy : public Enemy {
public:

	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) override;
	void Update()override;
	void Draw()override;


private:

};
