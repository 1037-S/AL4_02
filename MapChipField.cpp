#include "MapChipField.h"
#include <fstream>
#include <map>
#include <sstream>

using namespace KamataEngine;

namespace {
// 複数の文字でもマップチップの識別を可能にしています
// (例えば、{"KB",  MapchipType::kBlock      },と書いても問題なく動けるようになっています)
std::map<std::string, MapchipType> mapChipTypeTable = {
    {"B",  MapchipType::kBlock    },
    {"P",  MapchipType::kPlayer   },
    {"NE", MapchipType::kNormalEnemy},
    {"BE", MapchipType::kBossEnemy},
    {"G",  MapchipType::kGoal     },
};
} // namespace

MapChipField::~MapChipField() {}

void MapChipField::ResetMapChipData() {
	// マップチップデータをリセットする
	mapChipData_.data.clear();
	mapChipData_.data.resize(kNumBlockVirtical_);
	for (std::vector<MapchipDataUnit>& mapChipDataLine : mapChipData_.data) {
		mapChipDataLine.resize(kNumBlockHorizontal_);
	}
}

void MapChipField::LoadMapChipCsv(const std::string& filePath) {
	// マップチップデータをリセットする
	ResetMapChipData();

	// ファイルを開く
	std::ifstream file;
	file.open(filePath);
#ifdef _DEBUG
	assert(file.is_open());
#endif // _DEBUG

	// マップチップCSV
	std::stringstream mapChipCsv;
	// ファイルの内容を文字列ストリームにコピー
	mapChipCsv << file.rdbuf();
	// ファイルを閉じる
	file.close();

	// CSVからマップチップデータを読み込む
	for (uint32_t i = 0; i < kNumBlockVirtical_; ++i) {
		std::string line;
		getline(mapChipCsv, line);

		// 1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream lineStream(line);

		for (uint32_t j = 0; j < kNumBlockHorizontal_; ++j) {
			std::string word;
			std::getline(lineStream, word, ',');

			if (!word.empty() && word.back() == '\r') {
				word.pop_back();
			}

			// 空白の場合はスキップする
			if (word.empty()) {
				continue;
			}

			std::string chipTypeStr = "";
			uint8_t subID = 0;

			//// 先頭文字がいずれかのマップチップ種別に該当数か確認
			// if (!mapChipTypeTable.contains(word[kChipType])) {
			//	continue;
			// }

			//// 先頭文字でマップチップのタイプを判別
			// mapChipData_.data[i][j].type = mapChipTypeTable[word[kChipType]];

			//// サブIDを含まない場合はスキップする(0番で固定)
			// if (word.size() <= kChipSubID) {
			//	mapChipData_.data[i][j].subID = 0;
			//	continue;
			// }

			// サブIDを設定
			// mapChipData_.data[i][j].subID = static_cast<uint8_t>(word[kChipSubID] - '0');

			// 文字列内の数字以外の部分（英字）を抽出
			size_t numPos = word.find_first_of("0123456789");
			if (numPos != std::string::npos) {
				chipTypeStr = word.substr(0, numPos);
				// 数字部分をサブIDとして取得
				subID = static_cast<uint8_t>(std::stoi(word.substr(numPos)));
			} else {
				chipTypeStr = word; // 数字がない場合は全体を識別子とする
			}

			// 2. テーブル内に定義された識別子か確認
			if (!mapChipTypeTable.contains(chipTypeStr)) {
				continue;
			}

			// 3. データにセットする
			mapChipData_.data[i][j].type = mapChipTypeTable[chipTypeStr];
			mapChipData_.data[i][j].subID = subID;
		}
	}
}

IndexSet MapChipField::GetMapchipIndexSetByPosition(const Vector3& position) {
	IndexSet indexSet = {};

	indexSet.xIndex = static_cast<uint32_t>((position.x + kBloakWidth_ / 2) / kBloakWidth_);
	uint32_t inversZIndex = static_cast<uint32_t>((position.z + kBloakHeight_ / 2) / kBloakHeight_);
	indexSet.zIndex = kNumBlockVirtical_ - 1 - inversZIndex;
	
	return indexSet;
}

MapChipField::Rect MapChipField::GetRectByIndex(uint32_t xIndex, uint32_t zIndex) {
	// 指定ブロックの中心座標を取得する
	Vector3 center = GetMapchipPostionByIndex(xIndex, zIndex);
	Rect rect;
	rect.left = center.x - kBloakWidth_ / 2.0f;
	rect.right = center.x + kBloakWidth_ / 2.0f;
	rect.back = center.z - kBloakHeight_ / 2.0f;
	rect.front = center.z + kBloakHeight_ / 2.0f;

	return rect;
}

MapchipType MapChipField::GetMapchipTypeByIndex(uint32_t xIndex, uint32_t zIndex) {
	if (xIndex >= kNumBlockHorizontal_ || zIndex >= kNumBlockVirtical_) {
		return MapchipType::kBlock;
	}

	return mapChipData_.data[zIndex][xIndex].type;
}

Vector3 MapChipField::GetMapchipPostionByIndex(uint32_t xIndex, uint32_t zIndex) { return Vector3(kBloakWidth_ * xIndex,0, kBloakHeight_ * (kNumBlockVirtical_ - 1 - zIndex)); }

uint8_t MapChipField::GetMapchipSubIDByIndex(uint32_t xIndex, uint32_t zIndex) {
	if (xIndex < 0 || kNumBlockHorizontal_ - 1 < xIndex) {
		return 0;
	}
	if (zIndex < 0 || kNumBlockVirtical_ - 1 < zIndex) {
		return 0;
	}

	return mapChipData_.data[zIndex][xIndex].subID;
}
