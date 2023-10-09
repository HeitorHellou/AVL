#pragma once

#include <iostream>
#include <vector>
#include "GridItem.h"
#include "Coordinates.h"
#include "GridItemAnchor.h"

namespace avl 
{
	 class Grid 
	 {
	 public:
		  Grid();
		  Grid(int screenWidth, int screenHeight, GridItemAnchor itemAnchor, int itemSize = 100);
		  ~Grid();
	 private:
		  std::vector<GridItem> items;
		  int itemSize;
		  int centerColumn;
		  GridItemAnchor itemAnchor;
	 public:
		  int itemQuantity;
	 public:
		  std::vector<GridItem> GetItems();
		  int GetItemSize();
		  Coordinates SetItemPositionAnchor(int x, int y);
		  Coordinates GetCurrentPosition(int line, int column);
		  int GetLinePosition(int line);
		  int GetColumnPosition(int column);
		  int GetCenterColumn();
		  GridItemAnchor GetItemAnchor();
		  Coordinates CalculateGridCircleCoordinates(int radius, int line, int column);
		  Coordinates CalculateGridTextCoordinates(int scale, int line, int column);
	 };
}