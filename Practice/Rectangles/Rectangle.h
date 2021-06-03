#pragma once

class Rectangle
{
public:
	float left;
	float right;
	float top;
	float bottom;
	Rectangle(float left, float right, float top, float bottom) {
		this->left = left;
		this->right = right;
		this->top = top;
		this->bottom = bottom;
	}
};