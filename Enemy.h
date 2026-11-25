#pragma once
#include "Character.h"
#include "Vector2Function.h"

class Player;

class Enemy : public Character {
public:
	virtual void SetTarget(Player* target) { target_ = target; }
	//virtual bool IsPlayerInSight() const;
	virtual bool CanDetectPlayer(const KamataEngine::Vector3& enemyPos, const KamataEngine::Vector3& playerPos, float detectRange) ;

protected:
	Player* target_ = nullptr;
	Vector2Function Vector2F_;
};
