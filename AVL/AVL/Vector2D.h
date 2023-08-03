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
		Vector2D();
		Vector2D(T x, T y) : _x{ x }, _y{ y } { }
	public:
		friend std::ostream& operator<<(std::ostream& out, const Vector2D<T>& v) { out << "(" << v._x << ", " << v._y << ")"; return out; };
		friend Vector2D operator+(const Vector2d<T>& other) { var x = _x + a._x; var y = _y + a._y; return new Vector2D(x, y); };
		friend Vector2D operator-(const Vector2d<T>& other) { var x = _x - a._x; var y = _y - a._y; return new Vector2D(x, y); };
		friend Vector2D operator/(const Vector2d<T>& other) { var x = a._x / _x; var y = a._y / _y; return new Vector2D(x, y);};
		friend Vector2D operator*(const Vector2d<T>& other) { return Vector2D(_x * a._x, _y * a._y); };
		friend Vector2D operator>(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator<(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator>=(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator<=(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator+=(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator-=(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator*=(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator==(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator!=(const Vector2d<T>& a, const Vector2d<T>& b) { };
		friend Vector2D operator!==(const Vector2d<T>& a, const Vector2d<T>& b) { };
	}; // class Vector2D

	typedef Vector2D<uint32_t> Vector2u;
	typedef Vector2D<int32_t> Vector2i;
	typedef Vector2D<float> Vector2f;
} // namespace avl