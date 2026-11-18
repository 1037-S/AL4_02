#pragma once
#include "Character.h"

class Player;

class Enemy : public Character {
public:
	virtual void SetTarget(Player* target) { target_ = target; }
	virtual bool IsPlayerInSight() const;
	virtual bool CanDetectPLayer(const KamataEngine::Vector3& enemyPos, const KamataEngine::Vector3& playerPos, float detectRange) const;

protected:
	Player* target_ = nullptr;
};
