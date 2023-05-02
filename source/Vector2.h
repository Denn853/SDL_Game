#pragma once

class Vector2 {
public: 
	float x;
	float y;

	Vector2()
		: x(0.0f), y(0.0f) {}

	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 operator+ (Vector2 other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator- (Vector2 other) {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator* (float other) {
		return Vector2(x * other, y * other);
	}
};