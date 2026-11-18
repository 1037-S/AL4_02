#pragma once
#include "KamataEngine.h"
#include "Matrix4x4Function.h"
#include "Vector3Function.h"
class LerpFunction {
public:
	float Lerp(float start, float end, float tMax, float t);
	float Lerp(float start, float end, float t);
	KamataEngine::Vector3 Lerp(const KamataEngine::Vector3& start, const KamataEngine::Vector3& end, float t);
};
