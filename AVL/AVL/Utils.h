#pragma once

namespace avl 
{
	 class Utils 
	 {
	 public:
		  struct PointerNode {
				int data;
				PointerNode* left;
				PointerNode* right;
		  };

		  struct Node
		  {
				float x;
				float y;
				int value;
		  };

		  struct Edge {
				int startNode;
				int endNode;
		  };

		  PointerNode* CreatePointerNode(int data) {
				PointerNode* newNode = new PointerNode;
				newNode->data = data;
				newNode->left = newNode->right = nullptr;
				return newNode;
		  }
	 };
}