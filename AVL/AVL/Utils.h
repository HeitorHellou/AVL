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

		  struct PointerGridNode
		  {
				int data;
				PointerGridNode* left;
				PointerGridNode* right;
				int row;
				int column;
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

		  PointerGridNode* CreatePointerGridNode(int data) {
				PointerGridNode* newNode = new PointerGridNode;
				newNode->data = data;
				newNode->left = newNode->right = nullptr;

				return newNode;
		  }
	 };
}