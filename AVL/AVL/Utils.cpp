#include <cmath>

#include "Utils.h"

using namespace avl;

Grid::Grid() : _columns{ 0 }, _rows{ 0 }, _cellWidth{ 0 }, _cellHeight{ 0 } {};

void Grid::setGrid(uint32_t width, uint32_t height, int row, int col) 
{
    _columns = row;
    _rows = col;
    _cellWidth = width / row;
    _cellHeight = height / col;
}

void Grid::setGrid(uint32_t width, uint32_t height, int treeHeight)
{
    _cellWidth = width;
    _cellHeight = height / treeHeight;
    _columns = pow(treeHeight, 2) - 1;
    _rows = treeHeight;
}