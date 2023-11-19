#pragma once

#include <memory>

namespace avl 
{
	 class Structs
	 {
	 public:
		 // Graph
		 struct Node
		 {
			 float x;
			 float y;
			 float distance;
			 int previous;
			 bool visited;
		 };

		 struct Edge 
		 {
			 int startNode;
			 int endNode;
			 int weight;
		 };

		 // Tree
		 struct TreeNode
		 {
			 int data;
			 std::shared_ptr<TreeNode> left;
			 std::shared_ptr<TreeNode> right;
		 };
	 };

	 class Grid
	 {
	 private:
		 int _rows;
		 int _columns;
		 int _cellWidth;
		 int _cellHeight;
	 public:
		 Grid();
		 // Creates a grid based on screen size and number of desired rows/columns
		 void setGrid(uint32_t width, uint32_t height, int row, int col);
		 // Creates a grid based on screen size and height of the tree
		 void setGrid(uint32_t width, uint32_t height, int treeHeight);
		 // Get current cell width
		 int getCellWidth();
		 // Get current cell height
		 int getCellHeight();
	 };
}