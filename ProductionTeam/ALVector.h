#pragma once
#include <Matrix4x4.h>
#include <Vector2.h>
#include <Vector3.h>
#include <assert.h>
#include <cmath>
#include <stdio.h>

Vector3 Add(const Vector3& v1, const Vector3& v2);
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

Vector3 Multiply(float scalar, const Vector3& v);

float Dot(const Vector3& v1, const Vector3& v2);

float Length(const Vector3& v);

Vector3 Normalize(const Vector3& v);

Matrix4x4 Add(Matrix4x4 a, Matrix4x4 b);

Matrix4x4 Subtract(Matrix4x4 a, Matrix4x4 b);

Matrix4x4 Multiply(Matrix4x4 a, Matrix4x4 b);

Matrix4x4 Inverse(Matrix4x4 a);

Matrix4x4 Transpose(Matrix4x4 a);

Matrix4x4 MakeIdentity4x4();

Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

Matrix4x4 MakeScaleMatrix(const Vector3& scale);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

Matrix4x4 MakerotateXMatrix(float radian);

Matrix4x4 MakerotateYMatrix(float radian);

Matrix4x4 MakerotateZMatrix(float radian);
Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 rotate, Vector3 translate);
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip, float farClip);
Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth);
Vector3 Cross(const Vector3& v1, const Vector3& v2);

Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);