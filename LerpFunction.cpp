#include "LerpFunction.h"

using namespace KamataEngine;

float LerpFunction::Lerp(float start, float end, float tMax, float t) {
	float newt = t / tMax;
	newt = 1.0f - newt;
	float easedt = newt * newt;

	return (1.0f - easedt) * start + easedt * end;
}

float LerpFunction::Lerp(float start, float end, float t) { return (1.0f - t) * start + t * end; }

Vector3 LerpFunction::Lerp(const KamataEngine::Vector3& start, const KamataEngine::Vector3& end, float t) {
	Vector3 result;
	result.x = Lerp(start.x, end.x, t);
	result.y = Lerp(start.y, end.y, t);
	result.z = Lerp(start.z, end.z, t);
	return result;
}
