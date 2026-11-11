#pragma once
#include "KamataEngine.h"
class Matrix4x4Function {
public:
	// 1.行列の加法
	KamataEngine::Matrix4x4 Add(const KamataEngine::Matrix4x4& m1, const KamataEngine::Matrix4x4& m2);
	// 2.行列の減法
	KamataEngine::Matrix4x4 Subtract(const KamataEngine::Matrix4x4& m1, const KamataEngine::Matrix4x4& m2);
	// 3.行列の積
	KamataEngine::Matrix4x4 Multiply(const KamataEngine::Matrix4x4& m1, const KamataEngine::Matrix4x4& m2);
	// 4.逆行列
	KamataEngine::Matrix4x4 Inverse(const KamataEngine::Matrix4x4& m);
	// 5.転置行列
	KamataEngine::Matrix4x4 Transpose(const KamataEngine::Matrix4x4& m);
	// 6.単位行列の作成
	KamataEngine::Matrix4x4 MakeIdentity4x4();
	// 1.X軸回転行列
	KamataEngine::Matrix4x4 MakeRotateXMatrix(float radian);
	// 2.Y軸回転行列
	KamataEngine::Matrix4x4 MakeRotateYMatrix(float radian);
	// 3.Z軸回転行列
	KamataEngine::Matrix4x4 MakeRotateZMatrix(float radian);
	// 4.XYZ軸回転行列
	void MakeRotateXYZMatrix();

	void SetRotate(const KamataEngine::Vector3& rotate) { rotate_ = rotate; }
	const KamataEngine::Matrix4x4& GetRotateXYZMatrix() const { return rotateXYZMatrix_; }

	// 1.透視投影行列
	KamataEngine::Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	// 2.正射影行列
	KamataEngine::Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
	// 3.ビューポート行列
	KamataEngine::Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

private:
	KamataEngine::Matrix4x4 rotateMatrixX_;
	KamataEngine::Matrix4x4 rotateMatrixY_;
	KamataEngine::Matrix4x4 rotateMatrixZ_;
	KamataEngine::Matrix4x4 rotateXYZMatrix_;
	KamataEngine::Vector3 rotate_;
	

};
