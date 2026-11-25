#include "Enemy.h"

using namespace KamataEngine;

bool Enemy::CanDetectPlayer(const KamataEngine::Vector3& enemyPos, const KamataEngine::Vector3& playerPos,float detectRange) { 
	Vector2 diff{
		playerPos.x - enemyPos.x,
		playerPos.z - enemyPos.z
	};
	// ベクトルの長さを求めて比較
	float distance = Vector2F_.Length(diff);
	return distance <= detectRange;
}
