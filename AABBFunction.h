#pragma once
#include "KamataEngine.h"

struct AABBBoxToBox {                  // 軸平行境界箱(Axis-Allgned Bounding-Box)
	KamataEngine::Vector3 min; //!< 最小点
	KamataEngine::Vector3 max; //!< 最大点
};
class AABBFunction {
public:
	bool IsCollision(const AABBBoxToBox& aabb1, const AABBBoxToBox& aabb2);
};
