#pragma once

namespace avl
{
	 class Coordinates
	 {
	 public:
		  Coordinates();
		  Coordinates(int x, int y);
		  ~Coordinates();
	 private:
		  int x;
		  int y;
	 public:
		  int GetX();
		  int GetY();
	 };
}