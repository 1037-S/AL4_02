#include "Vector3Function.h"
using namespace KamataEngine;
// 加算
Vector3 Vector3Function::Add(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2) {
	Vector3 result = {};

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}
// 減算
Vector3 Vector3Function::Subtract(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2) {
	Vector3 result = {};

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
}
// スカラー倍
Vector3 Vector3Function::Multiply(float scalar, const KamataEngine::Vector3& v) {
	Vector3 result = {};

	result.x = scalar * v.x;
	result.y = scalar * v.y;
	result.z = scalar * v.z;

	return result;
}
// 内積
float Vector3Function::Dot(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2) {
	float result = {};

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return result;
}
// 長さ(ノルム)
float Vector3Function::Length(const KamataEngine::Vector3& v) {
	float result = {};

	result = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

	return result;
}
// 正規化
Vector3 Vector3Function::Normalize(const KamataEngine::Vector3& v) {
	Vector3 result = {};

	float len = Length(v);

	if (len == 0.0f) {
		return {0.0f, 0.0f, 0.0f};
	}

	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;

	return result;
}

Vector3 Vector3Function::Cross(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2) {
	Vector3 result = {};

	result.x = (v1.y * v2.z - v1.z * v2.y);
	result.y = (v1.z * v2.x - v1.x * v2.z);
	result.z = (v1.x * v2.y - v1.y * v2.x);

	return result;
}

float Vector3Function::Lerp(float start, float end, float tMax, float t) {
	float newt = t / tMax;
	newt = 1.0f - newt;
	float easedt = newt * newt;

	return (1.0f - easedt) * start + easedt * end;
}

float Vector3Function::Lerp(float start, float end, float t) { return (1.0f - t) * start + t * end; }
