#pragma once

#include <stdlib.h>

#include "Vector2.h"

#define GAME_WIDTH 500
#define GAME_HEIGHT 500

inline float CalculateRadius(int width, int height) {

	float a = ((float)width / 2.f);
	a *= a;	//power of two

	float b = ((float)height / 2.f);
	b *= b;	//power of two

	float h = sqrt(a + b); // THIS IS THE RADIUS

	return h;
}

inline Vector2 CalculatePositionInRadius(float r) {

	Vector2 perimeterPosition;

	float angle = rand() % 360;
	angle *= M_PI / 180.0f; //Conversió de graus a radiants

	perimeterPosition.x = cos(angle) * r;
	perimeterPosition.y = sin(angle) * r;

	return perimeterPosition;
}

inline Vector2 ClampPositionToRectangle(Vector2 pos, float halfWidth, float halfHeight) {

	if (pos.y > halfHeight) {	// TOP CLAMP
		pos.y = halfHeight;
	}

	if (pos.y < -halfHeight) {	// BOTTOM CLAMP
		pos.y = -halfHeight;
	}

	if (pos.x < -halfWidth) {	// LEFT CLAMP
		pos.x = -halfWidth;
	}

	if (pos.x > halfWidth) {	// RIGHT CLAMP
		pos.x = halfWidth;
	}

	return pos;
}

inline bool CheckCollision(Vector2 posA, float radiusA, Vector2 posB, float radiusB) {
	Vector2 aToB = posB - posA; //Destí menys Origen
	float distanceSquared = aToB.x * aToB.x + aToB.y * aToB.y;
	
	float squaredRadiusSum = radiusA + radiusB;
	squaredRadiusSum *= squaredRadiusSum;

	return distanceSquared < squaredRadiusSum;
}

inline bool CheckPointInsideCenteredRectangle(Vector2 point, Vector2 rectCenter, int w, int h) {	// Buttons
	
	//point = mouse
	//rect = buton

	float distX = abs(point.x - rectCenter.x);
	float distY = abs(point.y - rectCenter.y);

	bool insideX = distX < (float)w / 2.0f;
	bool insideY = distY < (float)h / 2.0f;

	return insideX && insideY;
}