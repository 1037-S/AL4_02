#pragma once
#include "KamataEngine.h"
#include <vector>

enum class MapchipType {
	kBlank,     // 空白
	kBlock,     // ブロック
	kPlayer,    // プレイヤー
	kNormalEnemy, // ザコ敵
	kBossEnemy, // ボス敵
	kGoal,
};

struct IndexSet {
	uint32_t xIndex;
	//uint32_t yIndex;
	uint32_t zIndex;
};

struct MapchipDataUnit {
	MapchipType type; // マップチップの種別
	uint8_t subID;    // サブID
};

struct MapChipData {
	std::vector<std::vector<MapchipDataUnit>> data;
};

class MapChipField {
public:
	// 矩形範囲
	struct Rect {
		float left;   // 左端
		float right;  // 右端
		float back;   // 手前
		float front;  // 奥
	};

	// マップチップCSVの文字番号
	enum MapChipCharInex {
		kChipType = 0,  // マップチップタイプ
		kChipSubID = 1, // サブID
	};

	~MapChipField();

	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filePath);
	IndexSet GetMapchipIndexSetByPosition(const KamataEngine::Vector3& position);
	Rect GetRectByIndex(uint32_t xIndex, uint32_t zIndex);

	MapchipType GetMapchipTypeByIndex(uint32_t xIndex, uint32_t zIndex);
	KamataEngine::Vector3 GetMapchipPostionByIndex(uint32_t xIndex, uint32_t zIndex);

	uint8_t GetMapchipSubIDByIndex(uint32_t xIndex, uint32_t zIndex);
	void SetkNumBlockVirtical(uint32_t kNumBlockVirtical) { kNumBlockVirtical = kNumBlockVirtical_; }
	uint32_t GetNumBlockVirtical() { return kNumBlockVirtical_; }
	void SetNumBlockHorizontal(uint32_t kNumBlockHorizontal) { kNumBlockHorizontal = kNumBlockHorizontal_; }
	uint32_t GetkNumBlockHorizontal() { return kNumBlockHorizontal_; }

	float GetBloakWidth() { return kBloakWidth_; }
	float GetBloakHeight() { return kBloakHeight_; }

private:
	MapChipData mapChipData_;

	MapchipType mapChipType_;

	// 1ブロックのサイズ
	static inline const float kBloakWidth_ = 1.0f;
	static inline const float kBloakHeight_ = 1.0f;

	// ブロックの個数
	static inline  uint32_t kNumBlockVirtical_ = 500;
	static inline  uint32_t kNumBlockHorizontal_ = 500;
};