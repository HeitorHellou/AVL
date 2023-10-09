#pragma once

namespace avl 
{
	 class GridItem 
	 {
	 public:
		  GridItem(int x, int y, int line, int column);
		  ~GridItem();
	 public:
		  int positionX;
		  int positionY;
		  int line;
		  int column;
		  bool used;
	 };
}