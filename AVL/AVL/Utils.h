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
			 int value;
		 };

		 struct Edge 
		 {
			 int startNode;
			 int endNode;
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
	 };
}