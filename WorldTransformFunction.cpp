#include "WorldTransformFunction.h"

using namespace KamataEngine;
// 1.平行移動行列
Matrix4x4 WorldTransformFunction::MakeTranslateMatrix(const KamataEngine::Vector3& translate) {
	Matrix4x4 result = {};

	result.m[0][0] = 1.0f;
	result.m[1][1] = 1.0f;
	result.m[2][2] = 1.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;

	return result;
}
// 2.拡大縮小行列
Matrix4x4 WorldTransformFunction::MakeScaleMatrix(const KamataEngine::Vector3& scale) {
	Matrix4x4 result = {};

	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;
	result.m[3][3] = 1.0f;

	return result;
}
// 3.座標変換
Vector3 WorldTransformFunction::Transform(const KamataEngine::Vector3& vector, const KamataEngine::Matrix4x4& matrix) {
	Vector3 result = {};

	result.x = (vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0]);
	result.y = (vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1]);
	result.z = (vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2]);
	float w = (vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3]);
	// assert(w!=0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}

Matrix4x4 WorldTransformFunction::MakeAffineMatrix(
	const KamataEngine::Vector3& scale, 
	const KamataEngine::Vector3& rotate, 
	const KamataEngine::Vector3& translate) {
	Matrix4x4 result = {};

	scaleMatrix_ = MakeScaleMatrix(scale);
	matrix4x4_.SetRotate(rotate);
	matrix4x4_.MakeRotateXYZMatrix();
	rotateMatrix_ = matrix4x4_.GetRotateXYZMatrix();
	translateMatrix_ = MakeTranslateMatrix(translate);

	result = matrix4x4_.Multiply(scaleMatrix_, matrix4x4_.Multiply(rotateMatrix_, translateMatrix_));

	return result;
}

void WorldTransformFunction::WorldTransformInitialize(KamataEngine::WorldTransform& worldTransform) { worldTransform.Initialize(); }

void WorldTransformFunction::WorldTransformUpdate(KamataEngine::WorldTransform& worldTransform) {
	// スケール、回転、平行移動を合成して行列を計算
	matrix4x4_.SetRotate(worldTransform.rotation_);
	matrix4x4_.MakeRotateXYZMatrix();
	Matrix4x4 scale = MakeScaleMatrix(worldTransform.scale_);
	Matrix4x4 rotation = matrix4x4_.GetRotateXYZMatrix();
	Matrix4x4 translation = MakeTranslateMatrix(worldTransform.translation_);

	worldTransform.matWorld_ = matrix4x4_.Multiply(scale, matrix4x4_.Multiply(rotation, translation));
	// 行列を定数バッファに転送
	worldTransform.TransferMatrix();
}
