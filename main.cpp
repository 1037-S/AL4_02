#include "KamataEngine.h"
#include <Windows.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	Initialize(L"LE2C_03_イトイ_シュウト_見下ろしアクション(仮)");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// メインループ
	while (true) {
		// エンジンの更新
		if (Update()) {
			break;
		}

		/// 更新処理

		/// 描画処理
		// 描画開始
		dxCommon->PreDraw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// 終了処理
	Finalize();

	return 0;
}
