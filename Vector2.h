#pragma once

template <typename T>
class Vector2
{
public:
	T x, y;

	Vector2(T x, T y);
};

template <typename T>
Vector2<T>::Vector2(T x, T y) {
	this->x = x;
	this->y = y;
}

 