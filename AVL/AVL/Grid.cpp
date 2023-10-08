#include "Grid.h"

using namespace avl;

Grid::Grid(int screenWidth, int screenHeight, int _itemSize) 
{ 
	 itemSize = _itemSize;

	 int lines = screenWidth / itemSize;
	 int collums = screenHeight / itemSize;

	 for (int i = 0; i < lines; i++) 
	 {
		  for (int j = 0; j < collums; j++) 
		  {
				items.push_back({ i * itemSize, j * itemSize });
		  }
	 }
}

Grid::Grid() { }
Grid::~Grid() { }

std::vector<GridItem> Grid::GetItems() 
{
	 return items;
}

int Grid::GetItemSize() 
{
	 return itemSize;
}