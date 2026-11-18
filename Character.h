#pragma once
#include "AABBFunction.h"
#include "KamataEngine.h"
#include "Matrix4x4Function.h"
#include "Vector3Function.h"
#include "WorldTransformFunction.h"


class Character {
public:
	virtual AABBFunction GetAABB();
	virtual AABBFunction GetBoxtoSphere();

	virtual void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);
	virtual void Update();
	virtual void Draw();

	// ゲッター
	virtual uint32_t GetMAXHP() const { return MAXHP_; }
	virtual uint32_t GetHP() const { return HP_; }
	virtual uint32_t GetATK() const { return ATK_; }
	virtual uint32_t GetDEF() const { return DEF_; }

	// ワールド座標を取得
	virtual KamataEngine::Vector3 GetWorldPosition() const;
	// virtual void SetMapChipField(MapChipField* mapChipField) { mapChipField_ = mapChipField; }
	virtual bool GetIsDead() const { return isDead_; }

protected:
	Matrix4x4Function matrix4x4F_;
	Vector3Function vector3F_;
	WorldTransformFunction worldTransformF_;
	AABBFunction aabbF_;
	// MapChipField* mapChipField_ = nullptr;
	KamataEngine::Model* model_;
	KamataEngine::Camera* camera_;
	KamataEngine::WorldTransform worldTransform_;
	float moveSpeed_;
	KamataEngine::Vector3 velocity_ = {0.0f, 0.0f, 0.0f};
	KamataEngine::Vector3 position_ = {0.0f, 0.0f, 0.0f};
	uint32_t MAXHP_;
	uint32_t HP_;
	uint32_t ATK_;
	uint32_t DEF_;
	bool isAttack_ = false;
	float width_;
	float height_;
	static inline const float kBlank = 0.01f;
	uint32_t kDeathAnimationTimer_;
	uint32_t kDeathAnimationDuration_;
	// デスフラグ
	bool isDead_ = false;
	bool isCollisionDidabled_ = false;
};

