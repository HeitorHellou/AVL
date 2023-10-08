#include "GridItem.h"

using namespace avl;

GridItem::GridItem(int x, int y) 
{ 
	 positionX = x;
	 positionY = y;
	 used = false;
}

GridItem::~GridItem() { }