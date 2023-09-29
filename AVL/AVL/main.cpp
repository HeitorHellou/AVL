#include <iostream>
#include "AVL.h"

int screenWidth = 1600;
int screenHeight = 800;

class ExampleQuicksort : public avl::AVL
{
private:
	std::vector<int> arr;  // The array to be sorted
	int margin;            // Margin around the bars
	int spacing;           // Spacing between the bars
	bool sortingComplete;  // Flag to track if sorting is complete

private:
	int partition(std::vector<int>& arr, int low, int high)
	{
		int pivotIndex = (low + high) / 2;
		int pivot = arr[pivotIndex];
		int i = low;
		int j = high;

		drawArray(pivotIndex, i, j, false);

		while (true)
		{
			if (arr[i] <= pivot)
				i++;
			if (arr[j] >= pivot)
				j--;

			if (i >= j) 
				return j;
			
			drawArray(pivotIndex, i, j, false);

			if (arr[i] >= pivot && arr[j] <= pivot) 
			{
				drawArray(pivotIndex, i, j, true);
				std::swap(arr[i], arr[j]);
				pivotIndex = (pivotIndex == i) ? j : (pivotIndex == j) ? i : pivotIndex;
			}
		}
	}

	void drawArray(int pivotIndex, int lowIndex, int highIndex, bool toChange)
	{
		// Draw the bars with colors
		Clear(avl::BLACK);

		int maxElement = *std::max_element(arr.begin(), arr.end());
		int barWidth = (screenWidth - 2 * margin - (arr.size() - 1) * spacing) / arr.size();
		float scaleFactor = static_cast<float>(screenHeight - 2 * margin) / static_cast<float>(maxElement);

		for (size_t k = 0; k < arr.size(); ++k)
		{
			int barHeight = static_cast<int>(arr[k] * scaleFactor);
			int x = margin + k * (barWidth + spacing);
			int y = screenHeight - margin - barHeight;

			sf::Color barColor = avl::WHITE;
			if (static_cast<int>(k) == pivotIndex)
			{
				barColor = avl::GREEN;  // Highlight pivot in green
			}
			else if (static_cast<int>(k) == lowIndex)
			{
				barColor = (toChange) ? avl::RED : avl::BLUE; // Highlight left index in blue
			}
			else if (static_cast<int>(k) == highIndex)
			{
				barColor = (toChange) ? avl::RED : avl::YELLOW; // Highlight right index in yellow
			}

			FillRect(x, y, barWidth, barHeight, barColor);
		}
		Display();

		// Add a delay of 3 seconds for visualization
		sf::sleep(sf::seconds(1.0f));
	}

	void quicksort(std::vector<int>& arr, int low, int high)
	{
		if (low < high) {
			int pivotIndex = partition(arr, low, high);

			quicksort(arr, low, pivotIndex);
			quicksort(arr, pivotIndex + 1, high);
		}
		else 
			sortingComplete = true;  // Set the flag to true when sorting is complete
	}

public:
	virtual void OnUserStart()
	{
		arr = { 10, 7, 4, 3, 6, 2, 8, 9, 1, 5 };
		margin = 10;
		spacing = 2;
	}

	virtual void OnUserUpdate()
	{
		if (!sortingComplete)
			quicksort(arr, 0, arr.size() - 1);  // Start the quicksort algorithm
		else
		{
			// Draw the bars with colors
			Clear(avl::BLACK);

			int maxElement = *std::max_element(arr.begin(), arr.end());
			int barWidth = (screenWidth - 2 * margin - (arr.size() - 1) * spacing) / arr.size();
			float scaleFactor = static_cast<float>(screenHeight - 2 * margin) / static_cast<float>(maxElement);

			for (size_t k = 0; k < arr.size(); ++k)
			{
				int barHeight = static_cast<int>(arr[k] * scaleFactor);
				int x = margin + k * (barWidth + spacing);
				int y = screenHeight - margin - barHeight;

				sf::Color barColor = avl::GREEN;

				FillRect(x, y, barWidth, barHeight, barColor);
			}
			Display();

			// Add a delay of 3 seconds for visualization
			sf::sleep(sf::seconds(1.0f));
		}
	}
};

struct TreeNode {
	 int data;
	 TreeNode* left;
	 TreeNode* right;
};
TreeNode* createNode(int data) {
	 TreeNode* newNode = new TreeNode;
	 newNode->data = data;
	 newNode->left = newNode->right = nullptr;
	 return newNode;
}

class Teste : public avl::AVL 
{
private:
	 TreeNode* root;
	 float horizontalSpacing;
public:
	 virtual void OnUserStart() 
	 {
		  root = createNode(1);
		  root->left = createNode(2);
		  root->right = createNode(3);
		  root->left->left = createNode(4);
		  root->left->right = createNode(5);

		  horizontalSpacing = 200.0f;
	 }

	 virtual void OnUserUpdate() 
	 {
		  drawTree(root, 400.0f, 50.0f, horizontalSpacing);
	 }

private:
	 void drawTree(TreeNode* root, float x, float y, float horizontalSpacing) {
		  if (root == nullptr) {
				return;
		  }

		  DrawCircle(x, y, 25, avl::BLUE);
		  DrawString(x + 20, y + 12, std::to_string(root->data), avl::ARIAL, avl::WHITE, 20);

		  if (root->left != nullptr) {

				DrawLine(x + 25, y + 50, x - horizontalSpacing, y + 100);
				drawTree(root->left, x - horizontalSpacing, y + 100, horizontalSpacing / 2);
		  }

		  if (root->right != nullptr) {

				DrawLine(x + 25, y + 50, x + horizontalSpacing, y + 100);
				drawTree(root->right, x + horizontalSpacing, y + 100, horizontalSpacing / 2);
		  }
	 }
};

int main()
{
	Teste demo;
	demo.SetFrameRate(60);
	demo.Render(800, 600);
	demo.Start(false);
	

	return 0;
}