#include "Enemy.h"

using namespace KamataEngine;

bool Enemy::CanDetectPLayer(const KamataEngine::Vector3& enemyPos, const KamataEngine::Vector3& playerPos,float detectRange) const { 
	Vector2 diff{
		playerPos.x - enemyPos.x,
		playerPos.z - enemyPos.z
	};
	
	float distance;

	return false;
}
