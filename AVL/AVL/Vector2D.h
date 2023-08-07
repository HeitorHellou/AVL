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
		friend std::ostream& operator<<(std::ostream& out, const Vector2D<T>& v) { out << "(" << v._x << ", " << v._y << ")"; return out; }
		friend Vector2D operator+(const Vector2D<T>& other) { return Vector2D(_x + other._x, _y + other._y); }
		friend Vector2D operator-(const Vector2D<T>& other) { return Vector2D(_x - other._x, _y - other._y); }
		friend Vector2D operator/(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return Vector2D(lhs._x / rhs._x, lhs._y / rhs._y); }
		friend Vector2D operator*(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return Vector2D(lhs._x * rhs._x, lhs._y * rhs._y); }
		friend bool operator>(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { double magnitude1 = std::sqrt(lhs._x * lhs._x + lhs._y * lhs._y); double magnitude2 = std::sqrt(rhs._x * rhs._x + rhs._y * rhs._y); return magnitude1 > magnitude2; }
		friend bool operator<(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { double magnitude1 = std::sqrt(lhs._x * lhs._x + lhs._y * lhs._y); double magnitude2 = std::sqrt(rhs._x * rhs._x + rhs._y * rhs._y); return magnitude1 < magnitude2; }
		friend bool operator>=(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return !(lhs < rhs); }
		friend bool operator<=(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return !(lhs > rhs); }
		Vector2D& operator+=(const Vector2D<T>& other) { _x += other._x; _y += other._y; return *this; }
		Vector2D& operator-=(const Vector2D<T>& other) { _x -= other._x; _y -= other._y; return *this; }
		Vector2D& operator*=(const Vector2D<T>& other) { _x *= other._x; _y *= other._y; return *this; }
		friend bool operator==(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return std::fabs(lhs._x - rhs._x) < 1e-6 && std::fabs(lhs._y - rhs._y) < 1e-6; }
		friend bool operator!=(const Vector2D<T>& lhs, const Vector2D<T>& rhs) { return !(lhs == rhs); }
	}; // class Vector2D

	typedef Vector2D<uint32_t> Vector2u;
	typedef Vector2D<int32_t> Vector2i;
	typedef Vector2D<float> Vector2f;
	template<typename T>
	inline Vector2D<T>::Vector2D() {	}
} // namespace avl