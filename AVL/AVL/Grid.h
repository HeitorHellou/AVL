#pragma once

#include <iostream>
#include <vector>
#include "GridItem.h"
#include "Coordinates.h"

namespace avl 
{
	 class Grid 
	 {
	 public:
		  Grid();
		  Grid(int screenWidth, int screenHeight, int itemSize = 100);
		  ~Grid();
	 private:
		  std::vector<GridItem> items;
		  int itemSize;
	 public:
		  std::vector<GridItem> GetItems();
		  int GetItemSize();
		  Coordinates SetItemPositionAnchor(int x, int y, int anchor, int itemSize);
	 };
}