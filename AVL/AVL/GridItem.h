#pragma once

namespace avl 
{
	 class GridItem 
	 {
	 public:
		  GridItem(int x, int y);
		  ~GridItem();
	 public:
		  int positionX;
		  int positionY;
		  bool used;
	 };
}