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

Coordinates Grid::SetItemPositionAnchor(int x, int y, int anchor, int itemSize)
{
	 switch (anchor)
	 {
	 case 0:
		  return { x + (int)(itemSize * 0.5f), y + (int)(itemSize * 0.25f) };
	 case 1:
		  return { x + (int)(itemSize * 0.5f), y + (int)(itemSize * 0.5f) };
	 case 2:
		  return { x + (int)(itemSize * 0.5f), y + (int)(itemSize * 0.75f) };
	 default:
		  return { 0, 0 };
	 }
}

Coordinates::Coordinates(int _x, int _y)
{ 
	 x = _x;
	 y = _y;
}

Coordinates::Coordinates() { }
Coordinates::~Coordinates() { }

int Coordinates::GetX() 
{
	 return x;
}

int Coordinates::GetY()
{
	 return y;
}