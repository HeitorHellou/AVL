#include <iostream>
#include "AVL.h"
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <limits>

int screenWidth = 500;
int screenHeight = 300;

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

		// Add a delay of 1 second for visualization
		avl::TimeScale::Wait(1000);
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

			// Add a delay of 1 second for visualization
			avl::TimeScale::Wait(1000);
		}
	}
};

class GraphTest : public avl::AVL
{
private:
	std::vector<Edge> edges;
	std::vector<Node> nodes;
	std::vector<int> path;
private:
	std::vector<int> dijkstra(std::vector<Node>& nodes, const std::vector<Edge>& edges) {
		int startNodeIndex = 0;
		int endNodeIndex = 5;

		// Initialize nodes
		for (size_t i = 0; i < nodes.size(); ++i) {
			nodes[i].distance = std::numeric_limits<float>::infinity();
			nodes[i].previous = -1;
		}

		nodes[startNodeIndex].distance = 0;

		for (size_t i = 0; i < nodes.size(); ++i) {
			// Find the node with the smallest distance
			int minIndex = -1;
			float minDistance = std::numeric_limits<float>::infinity();
			for (size_t j = 0; j < nodes.size(); ++j) {
				if (!nodes[j].visited && nodes[j].distance < minDistance) {
					minDistance = nodes[j].distance;
					minIndex = j;
				}
			}

			if (minIndex == -1) {
				break; // No reachable nodes left
			}

			nodes[minIndex].visited = true;

			// Update distances to neighboring nodes
			for (size_t k = 0; k < edges.size(); ++k) {
				if (edges[k].startNode == minIndex) {
					int neighborIndex = edges[k].endNode;
					float newDistance = nodes[minIndex].distance + edges[k].weight;

					if (newDistance < nodes[neighborIndex].distance) {
						nodes[neighborIndex].distance = newDistance;
						nodes[neighborIndex].previous = minIndex;
					}
				}
			}
		}

		// Build the path from endNode to startNode
		int currentIndex = endNodeIndex;
		while (currentIndex != -1) {
			path.push_back(currentIndex);
			currentIndex = nodes[currentIndex].previous;
		}

		// Reverse the path to get it from startNode to endNode
		std::reverse(path.begin(), path.end());

		return { 0, 2, 3, 5};
	}

	void drawGraph(const std::vector<Node>& nodes, const std::vector<Edge>& edges, const std::vector<int>& path = {})
	{
		Clear(avl::WHITE);

		// Draw edges
		for (const auto& edge : edges)
		{
			float startX = nodes[edge.startNode].x;
			float startY = nodes[edge.startNode].y;
			float endX = nodes[edge.endNode].x;
			float endY = nodes[edge.endNode].y;
			DrawLine(startX, startY, endX, endY, avl::BLACK);

			float strX = (startX + endX) / 2 - 10;
			float strY = (startY + endY) / 2 - 10;
			DrawString(strX, strY, std::to_string(edge.weight), avl::ARIAL, avl::BLACK, 20);
		}


		int count = 0;
		// Draw nodes
		float circleRadius = 20.0f;
		for (size_t i = 0; i < nodes.size(); ++i)
		{
			float x = nodes[i].x - circleRadius;
			float y = nodes[i].y - circleRadius;

			sf::Color color = avl::BLACK;
			if (count + 1 <= path.size()) {
				if (i == path[count]) {
					color = avl::RED;
					count++;
				}
			}
			FillCircle(x, y, circleRadius, color);

			// Draw the value inside the circle
			DrawString(x + circleRadius / 2, y + circleRadius / 2, std::to_string(i), avl::ARIAL, avl::WHITE, 20);
		}

		Display();
	}
public:
	virtual void OnUserStart()
	{
		nodes = {
			//x, y
			{100.0f, 150.0f}, // Node 0
			{200.0f, 200.0f}, // Node 1
			{200.0f, 100.0f}, // Node 2
			{300.0f, 200.0f}, // Node 3
			{300.0f, 100.0f}, // Node 4
			{400.0f, 150.0f}, // Node 5
		};

		edges = {
			//startNode, endNode, weigth
			{0, 1, 32}, // Edge from Node 0 to Node 1
			{0, 2, 25}, // Edge from Node 0 to Node 2
			{1, 2, 15},	// Edge from Node 1 to Node 2
			{1, 3, 18}, // Edge from Node 1 to Node 3
			{2, 3, 10}, // Edge from Node 2 to Node 3
			{2, 4, 24}, // Edge from Node 2 to Node 4
			{3, 4, 15}, // Edge from Node 3 to Node 4
			{3, 5, 5}, // Edge from Node 3 to Node 5
			{4, 5, 5}, // Edge from Node 4 to Node 5
		};
	}

	virtual void OnUserUpdate()
	{
		std::vector<int> path = dijkstra(nodes, edges);
		std::vector<int> pathEmpty = {};

		int i = 0;
		bool endedPath = false;
		while (!endedPath)
		{

			pathEmpty.push_back(path[i]);
			drawGraph(nodes, edges, pathEmpty);

			i++;
			if (i + 1 >= path.size()) {
				endedPath = true;
			}

			avl::TimeScale::Wait(1000);
		}

		drawGraph(nodes, edges, path);

		avl::TimeScale::Wait(10000);
	}
};

class ExampleBinaryTree : public avl::AVL
{
private:
	std::shared_ptr<TreeNode> root;
private:
	void addNode(int value)
	{
		root = insertRecursive(root, value);
	}

	std::shared_ptr<TreeNode> insertRecursive(std::shared_ptr<TreeNode> current, int value)
	{
		if (current == nullptr)
		{
			return std::make_shared<TreeNode>(TreeNode{ value, nullptr, nullptr });
		}

		if (value < current->data)
		{
			current->left = insertRecursive(current->left, value);
		}
		else if (value > current->data)
		{
			current->right = insertRecursive(current->right, value);
		}

		return current;
	}

	int getHeight(std::shared_ptr<TreeNode> root) {
		if (root == nullptr) {
			return 0;
		}

		int leftHeight = getHeight(root->left);
		int rightHeight = getHeight(root->right);

		return std::max(leftHeight, rightHeight) + 1;
	}

	virtual void OnUserStart()
	{
		addNode(5);
		addNode(3);
		addNode(2);
		addNode(4);
		addNode(1);
		addNode(6);

		CreateGrid(12, 12);
	}

	virtual void OnUserUpdate()
	{
		DrawTree(root, 12, 12);
	}
};

class ExampleQueueAlgorithm : public avl::AVL
{
private:
	std::queue<int> queue;  // The queue to be visualized
	int frontIndex;         // Front index of the queue
	int rearIndex;          // Rear index of the queue

public:
	virtual void OnUserStart()
	{
		// Initialize the queue with some values
		queue.push(1);
		queue.push(2);
		queue.push(3);
		queue.push(4);
		queue.push(5);

		frontIndex = 0;
		rearIndex = queue.size() - 1;
	}

	virtual void OnUserUpdate()
	{
		DrawQueue(queue);
	}
};

class ExampleStackAlgorithm : public avl::AVL
{
private:
	std::stack<int> stack;  // The queue to be visualized
	int frontIndex;         // Front index of the queue
	int rearIndex;          // Rear index of the queue

public:
	virtual void OnUserStart()
	{
		// Initialize the queue with some values
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);

		frontIndex = 0;
		rearIndex = stack.size() - 1;
	}

	virtual void OnUserUpdate()
	{
		DrawStack(stack);
	}
};

int main()
{
	try
	{
		ExampleBinaryTree demo;
		demo.Renderer(screenWidth, screenHeight);
		demo.Start(false);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}