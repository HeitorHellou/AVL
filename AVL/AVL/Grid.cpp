#include "Grid.h"

using namespace avl;

Grid::Grid(int screenWidth, int screenHeight, GridItemAnchor _itemAnchor, int _itemSize)
{
	 itemSize = _itemSize;
	 itemAnchor = _itemAnchor;

	 int lines = screenWidth / itemSize;
	 int columns = screenHeight / itemSize;

	 centerColumn = columns / 2;

	 for (int i = 0; i < lines; i++)
	 {
		  for (int j = 0; j < columns; j++)
		  {
				items.push_back({ i * itemSize, j * itemSize, j, i });
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

int Grid::GetLinePosition(int line)
{
	 return itemSize * line;
}

int Grid::GetColumnPosition(int column)
{
	 return itemSize * column;
}

int Grid::GetCenterColumn()
{
	 return centerColumn;
}

GridItemAnchor Grid::GetItemAnchor()
{
	 return itemAnchor;
}

Coordinates Grid::GetCurrentPosition(int line, int column)
{
	 Coordinates _coordinates;

	 for (int i = 0; i < items.size(); i++)
	 {
		  if (items.at(i).line == line && items.at(i).column == column)
		  {
				_coordinates = { items.at(i).positionX, items.at(i).positionY };
				break;
		  }
	 }

	 return _coordinates;
}

Coordinates Grid::SetItemPositionAnchor(int x, int y)
{
	 switch (itemAnchor)
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

Coordinates Grid::CalculateGridCircleCoordinates(int radius, int line, int column)
{
	 Coordinates _coordinates = GetCurrentPosition(line, column);

	 float circleX = _coordinates.GetX() - radius;
	 float circleY = _coordinates.GetY() - radius;

	 _coordinates = SetItemPositionAnchor(circleX, circleY);

	 return _coordinates;
}

Coordinates Grid::CalculateGridTextCoordinates(int scale, int line, int column) 
{
	 Coordinates _coordinates = GetCurrentPosition(line, column);

	 float textX = _coordinates.GetX() - (scale / 2);
	 float textY = _coordinates.GetY() - (scale / 2);

	 _coordinates = SetItemPositionAnchor(textX, textY);

	 return _coordinates;
}