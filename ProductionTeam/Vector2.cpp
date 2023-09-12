#include "Vector2.h"
 
Vector2 Add(const Vector2& a, const Vector2& b) {
	return{ a.x + b.x,a.y + b.y };
}

Vector2 Subtract(const Vector2& a, const Vector2& b) {
	return{ a.x - b.x,a.y - b.y };
}

float Length(const Vector2& v) {
	float length = 0;

	length = sqrtf(powf(v.x, 2) + powf(v.y, 2));

	return length;
}

Vector2 Normalize(const Vector2& v1) {
	Vector2 v2 = { 0, 0};
	float length = Length(v1);

	v2.x = v1.x / length;
	v2.y = v1.y / length;

	return v2;
}