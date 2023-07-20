#pragma once

#include <iostream>

namespace avl
{
	template <typename T>
	class Vector2D
	{
	public:
		T _x;
		T _y;
	public:
		Vector2D() {}
		Vector2D(T x, T y) : _x{ x }, _y{ y } { }
	public:
		friend std::ostream& operator<<(std::ostream& out, const Vector2D<T>& v) { out << "(" << v._x << ", " << v._y << ")"; return out; };
	}; // class Vector2D

	typedef Vector2D<uint32_t> Vector2u;
	typedef Vector2D<int> Vector2i;
	typedef Vector2D<float> Vector2f;
} // namespace avl