#pragma once
#include "KamataEngine.h"
class Vector3Function {
	// 加算
	KamataEngine::Vector3 Add(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
	// 減算
	KamataEngine::Vector3 Subtract(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
	// スカラー倍
	KamataEngine::Vector3 Multiply(float scalar, const KamataEngine::Vector3& v);
	// 内積
	float Dot(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
	// 長さ(ノルム)
	float Length(const KamataEngine::Vector3& v);
	// 正規化
	KamataEngine::Vector3 Normalize(const KamataEngine::Vector3& v);
	// クロス積(外積)(ベクトル積とも呼ばれる)
	KamataEngine::Vector3 Cross(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);

	float Lerp(float start, float end, float tMax, float t);
	float Lerp(float start, float end, float t);
};
