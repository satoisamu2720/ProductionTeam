#include "ALVector.h"

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 v3 = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	return v3;
};
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 v3 = {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	return v3;
};

Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 v3 = {v.x * scalar, v.y * scalar, v.z * scalar};
	return v3;
}

float Dot(const Vector3& v1, const Vector3& v2) {
	float dot;
	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return dot;
}

float Length(const Vector3& v) {
	float length;
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return length;
}

Vector3 Normalize(const Vector3& v) {
	float length;
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	Vector3 normalize{
	    v.x / length,
	    v.y / length,
	    v.z / length,
	};
	return normalize;
}

Matrix4x4 Add(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 add;
	add.m[0][0] = a.m[0][0] + b.m[0][0];
	add.m[0][1] = a.m[0][1] + b.m[0][1];
	add.m[0][2] = a.m[0][2] + b.m[0][2];
	add.m[0][3] = a.m[0][3] + b.m[0][3];
	add.m[1][0] = a.m[1][0] + b.m[1][0];
	add.m[1][1] = a.m[1][1] + b.m[1][1];
	add.m[1][2] = a.m[1][2] + b.m[1][2];
	add.m[1][3] = a.m[1][3] + b.m[1][3];
	add.m[2][0] = a.m[2][0] + b.m[2][0];
	add.m[2][1] = a.m[2][1] + b.m[2][1];
	add.m[2][2] = a.m[2][2] + b.m[2][2];
	add.m[2][3] = a.m[2][3] + b.m[2][3];
	add.m[3][0] = a.m[3][0] + b.m[3][0];
	add.m[3][1] = a.m[3][1] + b.m[3][1];
	add.m[3][2] = a.m[3][2] + b.m[3][2];
	add.m[3][3] = a.m[3][3] + b.m[3][3];
	return add;
}

Matrix4x4 Subtract(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 subtract;
	subtract.m[0][1] = a.m[0][1] - b.m[0][1];
	subtract.m[0][0] = a.m[0][0] - b.m[0][0];
	subtract.m[0][2] = a.m[0][2] - b.m[0][2];
	subtract.m[0][3] = a.m[0][3] - b.m[0][3];
	subtract.m[1][0] = a.m[1][0] - b.m[1][0];
	subtract.m[1][1] = a.m[1][1] - b.m[1][1];
	subtract.m[1][2] = a.m[1][2] - b.m[1][2];
	subtract.m[1][3] = a.m[1][3] - b.m[1][3];
	subtract.m[2][0] = a.m[2][0] - b.m[2][0];
	subtract.m[2][1] = a.m[2][1] - b.m[2][1];
	subtract.m[2][2] = a.m[2][2] - b.m[2][2];
	subtract.m[2][3] = a.m[2][3] - b.m[2][3];
	subtract.m[3][0] = a.m[3][0] - b.m[3][0];
	subtract.m[3][1] = a.m[3][1] - b.m[3][1];
	subtract.m[3][2] = a.m[3][2] - b.m[3][2];
	subtract.m[3][3] = a.m[3][3] - b.m[3][3];
	return subtract;
}

Matrix4x4 Multiply(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 multiply;
	multiply.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] +
	                   a.m[0][3] * b.m[3][0];
	multiply.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] +
	                   a.m[0][3] * b.m[3][1];
	multiply.m[0][2] = a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] +
	                   a.m[0][3] * b.m[3][2];
	multiply.m[0][3] = a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] +
	                   a.m[0][3] * b.m[3][3];
	multiply.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] +
	                   a.m[1][3] * b.m[3][0];
	multiply.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] +
	                   a.m[1][3] * b.m[3][1];
	multiply.m[1][2] = a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] +
	                   a.m[1][3] * b.m[3][2];
	multiply.m[1][3] = a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] +
	                   a.m[1][3] * b.m[3][3];
	multiply.m[2][0] = a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] +
	                   a.m[2][3] * b.m[3][0];
	multiply.m[2][1] = a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] +
	                   a.m[2][3] * b.m[3][1];
	multiply.m[2][2] = a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] +
	                   a.m[2][3] * b.m[3][2];
	multiply.m[2][3] = a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] +
	                   a.m[2][3] * b.m[3][3];
	multiply.m[3][0] = a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] +
	                   a.m[3][3] * b.m[3][0];
	multiply.m[3][1] = a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] +
	                   a.m[3][3] * b.m[3][1];
	multiply.m[3][2] = a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] +
	                   a.m[3][3] * b.m[3][2];
	multiply.m[3][3] = a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] +
	                   a.m[3][3] * b.m[3][3];

	return multiply;
}

Matrix4x4 Inverse(Matrix4x4 a) {
	Matrix4x4 result = {0};
	float x = a.m[0][0] * a.m[1][1] * a.m[2][2] * a.m[3][3] +
	          a.m[0][0] * a.m[1][2] * a.m[2][3] * a.m[3][1] +
	          a.m[0][0] * a.m[1][3] * a.m[2][1] * a.m[3][2] -
	          a.m[0][0] * a.m[1][3] * a.m[2][2] * a.m[3][1] -
	          a.m[0][0] * a.m[1][2] * a.m[2][1] * a.m[3][3] -
	          a.m[0][0] * a.m[1][1] * a.m[2][3] * a.m[3][1] -
	          a.m[0][1] * a.m[1][0] * a.m[2][2] * a.m[3][3] -
	          a.m[0][2] * a.m[1][0] * a.m[2][3] * a.m[3][1] -
	          a.m[0][3] * a.m[1][0] * a.m[2][1] * a.m[3][2] +
	          a.m[0][3] * a.m[1][0] * a.m[2][2] * a.m[3][1] +
	          a.m[0][2] * a.m[1][0] * a.m[2][1] * a.m[3][3] +
	          a.m[0][1] * a.m[1][0] * a.m[2][3] * a.m[3][2] +
	          a.m[0][1] * a.m[1][2] * a.m[2][0] * a.m[3][3] +
	          a.m[0][2] * a.m[1][3] * a.m[2][0] * a.m[3][1] +
	          a.m[0][3] * a.m[1][1] * a.m[2][0] * a.m[3][2] -
	          a.m[0][3] * a.m[1][2] * a.m[2][0] * a.m[3][1] -
	          a.m[0][2] * a.m[1][1] * a.m[2][0] * a.m[3][3] -
	          a.m[0][1] * a.m[1][3] * a.m[2][0] * a.m[3][2] -
	          a.m[0][1] * a.m[1][2] * a.m[2][3] * a.m[3][0] -
	          a.m[0][2] * a.m[1][3] * a.m[2][1] * a.m[3][0] -
	          a.m[0][3] * a.m[1][1] * a.m[2][2] * a.m[3][0] +
	          a.m[0][3] * a.m[1][2] * a.m[2][1] * a.m[3][0] +
	          a.m[0][2] * a.m[1][1] * a.m[2][3] * a.m[3][0] +
	          a.m[0][1] * a.m[1][3] * a.m[2][2] * a.m[3][0];

	if (x != 0) {
		result.m[0][0] = 1 / x *
		                 (a.m[1][1] * a.m[2][2] * a.m[3][3] + a.m[1][2] * a.m[2][3] * a.m[3][1] +
		                  a.m[1][3] * a.m[2][1] * a.m[3][2] - a.m[1][3] * a.m[2][2] * a.m[3][1] -
		                  a.m[1][2] * a.m[2][1] * a.m[3][3] - a.m[1][1] * a.m[2][3] * a.m[3][2]);

		result.m[0][1] = 1 / x *
		                 (-a.m[0][1] * a.m[2][2] * a.m[3][3] - a.m[0][2] * a.m[2][3] * a.m[3][1] -
		                  a.m[0][3] * a.m[2][1] * a.m[3][2] + a.m[0][3] * a.m[2][2] * a.m[3][1] +
		                  a.m[1][2] * a.m[2][1] * a.m[3][3] + a.m[0][1] * a.m[2][3] * a.m[3][2]);

		result.m[0][2] = 1 / x *
		                 (a.m[0][1] * a.m[1][2] * a.m[3][3] + a.m[0][2] * a.m[1][3] * a.m[3][1] +
		                  a.m[0][3] * a.m[1][1] * a.m[3][2] - a.m[0][3] * a.m[1][2] * a.m[3][1] -
		                  a.m[0][2] * a.m[1][1] * a.m[3][3] - a.m[0][1] * a.m[1][3] * a.m[3][2]);

		result.m[0][3] = 1 / x *
		                 (-a.m[0][1] * a.m[1][2] * a.m[2][3] - a.m[1][2] * a.m[1][3] * a.m[2][1] -
		                  a.m[0][3] * a.m[1][1] * a.m[2][2] + a.m[0][3] * a.m[1][2] * a.m[2][1] -
		                  a.m[0][2] * a.m[1][1] * a.m[2][3] + a.m[0][1] * a.m[1][3] * a.m[2][2]);

		result.m[1][0] = 1 / x *
		                 (-a.m[1][0] * a.m[2][2] * a.m[3][3] - a.m[1][2] * a.m[2][3] * a.m[3][0] -
		                  a.m[1][3] * a.m[2][0] * a.m[3][2] + a.m[1][3] * a.m[2][2] * a.m[3][0] +
		                  a.m[1][2] * a.m[2][0] * a.m[3][3] + a.m[1][0] * a.m[2][3] * a.m[3][2]);

		result.m[1][1] = 1 / x *
		                 (a.m[0][0] * a.m[2][2] * a.m[3][3] + a.m[0][2] * a.m[2][3] * a.m[3][0] +
		                  a.m[0][3] * a.m[2][0] * a.m[3][2] - a.m[0][3] * a.m[2][2] * a.m[3][0] -
		                  a.m[0][2] * a.m[2][0] * a.m[3][3] - a.m[0][0] * a.m[2][3] * a.m[3][2]);

		result.m[1][2] = 1 / x *
		                 (-a.m[0][0] * a.m[1][2] * a.m[3][3] - a.m[0][2] * a.m[1][3] * a.m[3][0] -
		                  a.m[0][3] * a.m[1][0] * a.m[3][2] + a.m[0][3] * a.m[1][2] * a.m[3][0] +
		                  a.m[0][2] * a.m[1][0] * a.m[3][3] + a.m[0][0] * a.m[1][3] * a.m[3][2]);

		result.m[1][3] = 1 / x *
		                 (a.m[0][0] * a.m[1][2] * a.m[2][3] + a.m[0][2] * a.m[1][3] * a.m[2][0] +
		                  a.m[0][3] * a.m[1][0] * a.m[2][2] - a.m[0][3] * a.m[1][2] * a.m[2][0] -
		                  a.m[1][2] * a.m[1][0] * a.m[2][3] - a.m[0][0] * a.m[1][3] * a.m[2][2]);

		result.m[2][0] = 1 / x *
		                 (a.m[1][0] * a.m[2][1] * a.m[3][3] + a.m[1][1] * a.m[2][3] * a.m[3][0] +
		                  a.m[1][3] * a.m[2][0] * a.m[3][1] - a.m[1][3] * a.m[2][1] * a.m[3][0] -
		                  a.m[1][1] * a.m[2][0] * a.m[3][3] - a.m[1][0] * a.m[2][3] * a.m[3][1]);

		result.m[2][1] = 1 / x *
		                 (-a.m[0][0] * a.m[2][1] * a.m[3][3] - a.m[1][0] * a.m[2][3] * a.m[3][0] -
		                  a.m[0][3] * a.m[2][0] * a.m[3][1] + a.m[0][3] * a.m[2][1] * a.m[3][0] +
		                  a.m[0][1] * a.m[2][0] * a.m[3][3] + a.m[0][0] * a.m[2][3] * a.m[3][1]);

		result.m[2][2] = 1 / x *
		                 (a.m[0][0] * a.m[1][1] * a.m[3][3] + a.m[0][1] * a.m[1][3] * a.m[3][0] +
		                  a.m[0][3] * a.m[1][0] * a.m[3][1] - a.m[0][3] * a.m[1][1] * a.m[3][0] -
		                  a.m[0][1] * a.m[1][3] * a.m[2][0] - a.m[0][0] * a.m[1][3] * a.m[3][1]);

		result.m[2][3] = 1 / x *
		                 (-a.m[0][0] * a.m[1][1] * a.m[2][3] - a.m[0][1] * a.m[1][3] * a.m[2][0] -
		                  a.m[0][3] * a.m[1][0] * a.m[2][1] + a.m[0][3] * a.m[1][1] * a.m[2][0] +
		                  a.m[0][1] * a.m[1][0] * a.m[2][3] + a.m[0][0] * a.m[1][3] * a.m[2][1]);

		result.m[3][0] = 1 / x *
		                 (-a.m[1][0] * a.m[2][1] * a.m[3][2] - a.m[1][1] * a.m[2][2] * a.m[3][0] -
		                  a.m[1][2] * a.m[2][0] * a.m[3][1] + a.m[1][2] * a.m[2][1] * a.m[3][0] +
		                  a.m[1][1] * a.m[2][0] * a.m[3][2] + a.m[1][0] * a.m[2][2] * a.m[3][1]);

		result.m[3][1] = 1 / x *
		                 (a.m[0][0] * a.m[2][1] * a.m[3][2] + a.m[0][1] * a.m[2][2] * a.m[3][0] +
		                  a.m[0][2] * a.m[2][0] * a.m[3][1] - a.m[0][2] * a.m[2][1] * a.m[3][0] -
		                  a.m[0][1] * a.m[2][0] * a.m[3][2] - a.m[0][0] * a.m[2][2] * a.m[3][1]);

		result.m[3][2] = 1 / x *
		                 (-a.m[0][0] * a.m[1][1] * a.m[3][2] - a.m[0][1] * a.m[1][2] * a.m[3][0] -
		                  a.m[0][2] * a.m[1][0] * a.m[3][1] + a.m[0][2] * a.m[1][1] * a.m[3][0] +
		                  a.m[0][1] * a.m[1][0] * a.m[3][2] + a.m[0][0] * a.m[1][2] * a.m[3][1]);

		result.m[3][3] = 1 / x *
		                 (a.m[0][0] * a.m[1][1] * a.m[2][2] + a.m[0][1] * a.m[1][2] * a.m[2][0] +
		                  a.m[0][2] * a.m[1][0] * a.m[2][1] - a.m[0][2] * a.m[1][1] * a.m[2][0] -
		                  a.m[0][1] * a.m[1][0] * a.m[2][2] - a.m[0][0] * a.m[1][2] * a.m[2][1]);
	}
	return result;
}

Matrix4x4 Transpose(Matrix4x4 a) {
	Matrix4x4 result;
	result.m[0][0] = a.m[0][0];
	result.m[1][0] = a.m[0][1];
	result.m[2][0] = a.m[0][2];
	result.m[3][0] = a.m[0][3];
	result.m[0][1] = a.m[1][0];
	result.m[1][1] = a.m[1][1];
	result.m[2][1] = a.m[1][2];
	result.m[3][1] = a.m[1][3];
	result.m[0][2] = a.m[2][0];
	result.m[1][2] = a.m[2][1];
	result.m[2][2] = a.m[2][2];
	result.m[3][2] = a.m[2][3];
	result.m[0][3] = a.m[3][0];
	result.m[1][3] = a.m[3][1];
	result.m[2][3] = a.m[3][2];
	result.m[3][3] = a.m[3][3];
	return result;
}

Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;
	return result;
}

Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;

	return result;
}

Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result;
	result.m[0][0] = scale.x;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = scale.y;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = scale.z;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] +
	           1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] +
	           1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] +
	           1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] +
	          1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

Matrix4x4 MakerotateXMatrix(float radian) {
	Matrix4x4 rotate;
	rotate.m[0][0] = 1.0f;
	rotate.m[0][1] = 0.0f;
	rotate.m[0][2] = 0.0f;
	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = 0.0f;
	rotate.m[1][1] = std::cos(radian);
	rotate.m[1][2] = std::sin(radian);
	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = 0.0f;
	rotate.m[2][1] = -std::sin(radian);
	rotate.m[2][2] = std::cos(radian);
	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f;
	rotate.m[3][1] = 0.0f;
	rotate.m[3][2] = 0.0f;
	rotate.m[3][3] = 1.0f;

	return rotate;
}

Matrix4x4 MakerotateYMatrix(float radian) {
	Matrix4x4 rotate;
	rotate.m[0][0] = std::cos(radian);
	rotate.m[0][1] = 0.0f;
	rotate.m[0][2] = -std::sin(radian);
	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = 0.0f;
	rotate.m[1][1] = 1.0f;
	rotate.m[1][2] = 0.0f;
	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = std::sin(radian);
	rotate.m[2][1] = 0.0f;
	rotate.m[2][2] = std::cos(radian);
	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f;
	rotate.m[3][1] = 0.0f;
	rotate.m[3][2] = 0.0f;
	rotate.m[3][3] = 1.0f;

	return rotate;
}

Matrix4x4 MakerotateZMatrix(float radian) {
	Matrix4x4 rotate;
	rotate.m[0][0] = std::cos(radian);
	rotate.m[0][1] = std::sin(radian);
	rotate.m[0][2] = 0.0f;
	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = -std::sin(radian);
	rotate.m[1][1] = std::cos(radian);
	rotate.m[1][2] = 0.0f;
	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = 0.0f;
	rotate.m[2][1] = 0.0f;
	rotate.m[2][2] = 1.0f;
	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f;
	rotate.m[3][1] = 0.0f;
	rotate.m[3][2] = 0.0f;
	rotate.m[3][3] = 1.0f;

	return rotate;
}

Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 rotate, Vector3 translate) {
	Matrix4x4 result;
	Matrix4x4 rotateX = MakerotateXMatrix(rotate.x);
	Matrix4x4 rotateY = MakerotateYMatrix(rotate.y);
	Matrix4x4 rotateZ = MakerotateZMatrix(rotate.z);
	Matrix4x4 ROTATE = Multiply(rotateX, Multiply(rotateY, rotateZ));

	result.m[0][0] = scale.x * ROTATE.m[0][0];
	result.m[0][1] = scale.x * ROTATE.m[0][1];
	result.m[0][2] = scale.x * ROTATE.m[0][2];
	result.m[0][3] = 0.0f;
	result.m[1][0] = scale.y * ROTATE.m[1][0];
	result.m[1][1] = scale.y * ROTATE.m[1][1];
	result.m[1][2] = scale.y * ROTATE.m[1][2];
	result.m[1][3] = 0.0f;
	result.m[2][0] = scale.z * ROTATE.m[2][0];
	result.m[2][1] = scale.z * ROTATE.m[2][1];
	result.m[2][2] = scale.z * ROTATE.m[2][2];
	result.m[2][3] = 0.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;

	return result;
};

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 result;

	result.m[0][0] = 1 / aspectRatio * 1 / std::tan(fovY / 2);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 1 / std::tan(fovY / 2);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = -nearClip * farClip / (farClip - nearClip);
	result.m[3][3] = 0;

	return result;
}

Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip, float farClip) {
	Matrix4x4 result;

	result.m[0][0] = 2 / (right - left);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 2 / (top - bottom);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1 / (nearClip - farClip);
	result.m[2][3] = 0;
	result.m[3][0] = (left + right) / (left - right);
	result.m[3][1] = (top + bottom) / (bottom - top);
	result.m[3][2] = nearClip / (nearClip - farClip);
	result.m[3][3] = 1;

	return result;
}

Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 result;

	result.m[0][0] = width / 2;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = -height / 2;
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = maxDepth - minDepth;
	result.m[2][3] = 0;
	result.m[3][0] = left + width / 2;
	result.m[3][1] = top + height / 2;
	result.m[3][2] = minDepth;
	result.m[3][3] = 1;

	return result;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m) {
	Vector3 result{
	    v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0],
	    v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1],
	    v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2],
	};
	return result;
}