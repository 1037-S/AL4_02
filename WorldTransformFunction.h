#pragma once
#include "KamataEngine.h"
#include "Matrix4x4Function.h"
#include "Vector3Function.h"
class WorldTransformFunction {
public:
	// 1.平行移動行列
	static KamataEngine::Matrix4x4 MakeTranslateMatrix(const KamataEngine::Vector3& translate);

	// 2.拡大縮小行列
	static KamataEngine::Matrix4x4 MakeScaleMatrix(const KamataEngine::Vector3& scale);

	// 3.座標変換
	static KamataEngine::Vector3 Transform(const KamataEngine::Vector3& vector, const KamataEngine::Matrix4x4& matrix);

	// アフィン変換行列
	KamataEngine::Matrix4x4 MakeAffineMatrix(const KamataEngine::Vector3& scale, const KamataEngine::Vector3& rotate, const KamataEngine::Vector3& translate);

	void WorldTransformInitialize(KamataEngine::WorldTransform& worldTransform);
	void WorldTransformUpdate(KamataEngine::WorldTransform& worldTransform);

private:
	Matrix4x4Function matrix4x4_;
	Vector3Function vector3_;

	KamataEngine::Matrix4x4 scaleMatrix_;
	KamataEngine::Matrix4x4 rotateMatrix_;
	KamataEngine::Matrix4x4 translateMatrix_;

	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
};
