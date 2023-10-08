#include <iostream>
#include "AVL.h"

int screenWidth = 800;
int screenHeight = 600;

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

class BinaryTreeTest : public avl::AVL 
{
private:
	 PointerNode* root;
public:
	 virtual void OnUserStart() 
	 {
		  root = CreatePointerNode(1);
		  root->left = CreatePointerNode(2);
		  root->right = CreatePointerNode(3);
		  root->left->left = CreatePointerNode(4);
		  root->left->right = CreatePointerNode(5);
	 }

	 virtual void OnUserUpdate() 
	 {
		  DrawTree(root, 400.0f, 100.0f, 150.0f, 100.0f);
	 }
};

class GraphTest : public avl::AVL
{
private:
	std::vector<Edge> edges;
	std::vector<Node> nodes;
public:
	virtual void OnUserStart()
	{
		nodes = {
			//column, line, value
			{100.0f, 100.0f, 10}, // Node 0
			{200.0f, 200.0f, 20}, // Node 1
			{300.0f, 100.0f, 15}, // Node 2
			{400.0f, 200.0f, 40}, // Node 3
			{200.0f, 100.0f, 25}  // Node 4
		};

		// Create edges between nodes
		edges = {
			{0, 1}, // Edge from Node 0 to Node 1
			{1, 2}, // Edge from Node 1 to Node 2
			{2, 3}, // Edge from Node 2 to Node 3
			{0, 4}, // Edge from Node 0 to Node 4
			{0, 3}  // Edge from Node 0 to Node 3
		};
	}

	virtual void OnUserUpdate()
	{
		DrawGraph(nodes, edges);
	}
};

class GridTest : public avl::AVL
{
private:
	 avl::Grid grid;
public:
	 virtual void OnUserStart()
	 {
		  grid = CreateGrid(screenWidth, screenHeight);
	 }

	 virtual void OnUserUpdate()
	 {
		  ViewGrid(grid);
	 }
};

int main()
{
	 try 
	 {
		  GridTest demo;
		  demo.SetFrameRate(60);
		  demo.Render(screenWidth, screenHeight);
		  demo.Start(false);
	 }
	 catch (const std::exception& e)
	 {
		  std::cout << "Exception: " << e.what() << std::endl;
	 }
	
	return 0;
}