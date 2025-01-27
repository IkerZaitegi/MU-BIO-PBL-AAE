#pragma once
typedef struct point_t {
	float t;
	float x;
	float y;
} point_t;

void freePoints(point_t** points);
