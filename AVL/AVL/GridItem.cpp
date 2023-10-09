#include "GridItem.h"

using namespace avl;

GridItem::GridItem(int x, int y, int _line, int _column) 
{ 
	 positionX = x;
	 positionY = y;
	 line = _line;
	 column = _column;
	 used = false;
}

GridItem::~GridItem() { }