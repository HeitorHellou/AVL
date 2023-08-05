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
		Vector2D() : _x{ 0 }, _y{ 0 } {}
		Vector2D(T x, T y) : _x{ x }, _y{ y } { }
	public:
		friend std::ostream& operator<<(std::ostream& out, const Vector2D<T>& v) { out << "(" << v._x << ", " << v._y << ")"; return out; };
		friend Vector2D operator+(const Vector2D<T>& other) { var x = _x + other._x; var y = _y + other._y; return new Vector2D(x, y); };
		friend Vector2D operator-(const Vector2D<T>& other) { var x = _x - other._x; var y = _y - other._y; return new Vector2D(x, y); };
		friend Vector2D operator/(const Vector2D<T>& other) { var x = other._x / _x; var y = other._y / _y; return new Vector2D(x, y);};
		friend Vector2D operator*(const Vector2D<T>& other) { return Vector2D(_x * other._x, _y * other._y); };
		friend Vector2D operator>(const Vector2D<T>& other) { double magnitude1 = std::sqrt(_x * _x + _y * _y); double magnitude2 = std::sqrt(other._x * other._x + other._y * other._y); return magnitude1 < magnitude2; };
		friend Vector2D operator<(const Vector2D<T>& other) { double magnitude1 = std::sqrt(_x * _x + _y * _y); double magnitude2 = std::sqrt(other._x * other._x + other._y * other._y); return magnitude1 > magnitude2; };
		friend Vector2D operator>=(const Vector2D<T>& other) { return !(*this < other); };
		friend Vector2D operator<=(const Vector2D<T>& other) { return !(*this > other); };
		friend Vector2D operator+=(const Vector2D<T>& other) { _x += other._x; _y += other._y; return *this; };
		friend Vector2D operator-=(const Vector2D<T>& other) { _x -= other._x; _y -= other._y; return *this; };
		friend Vector2D operator*=(const Vector2D<T>& other) { _x *= other._x; _y *= other._y; return *this; };
		friend Vector2D operator==(const Vector2D<T>& other) { return std::fabs(_x - other._x) < 1e-6 && std::fabs(_y - other._y) < 1e-6; };
		friend Vector2D operator!=(const Vector2D<T>& other) { return !(*this == other); };
		friend Vector2D operator!==(const Vector2D<T>& other) { return !(*this == other); };
	}; // class Vector2D

	typedef Vector2D<uint32_t> Vector2u;
	typedef Vector2D<int32_t> Vector2i;
	typedef Vector2D<float> Vector2f;
} // namespace avl