#include "NormalEnemy.h"

void NormalEnemy::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) {

// NULLポインタチェック
#ifdef _DEBUG
	assert(model);
	assert(camera);
#endif // _DEBUG

	worldTransformF_.WorldTransformInitialize(worldTransform_);
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	MAXHP_ = 10;
	HP_ = MAXHP_;
	ATK_ = 5;
	DEF_ = 5;
}

void NormalEnemy::Update() {}

void NormalEnemy::Draw() {}
