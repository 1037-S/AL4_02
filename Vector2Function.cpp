#include "Vector2Function.h"
using namespace KamataEngine;

float Vector2Function::Length(KamataEngine::Vector2& v) { 
	float result = {};

	result = sqrtf(v.x * v.x + v.y * v.y);

	return result;
}
