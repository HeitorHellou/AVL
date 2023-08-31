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

private:
	int partition(std::vector<int>& arr, int low, int high)
	{
		int pivotIndex = (low + high) / 2;
		int pivot = arr[pivotIndex];
		int i = low - 1;
		int j = high + 1;

		while (true) {
			do {
				i++;
			} while (arr[i] < pivot);

			do {
				j--;
			} while (arr[j] > pivot);

			if (i >= j)
				return j;

			// Swap the elements and update the visualization
			std::swap(arr[i], arr[j]);
			pivotIndex = (pivotIndex == i) ? j : (pivotIndex == j) ? i : pivotIndex;

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
				else if (static_cast<int>(k) == i || static_cast<int>(k) == j)
				{
					barColor = (static_cast<int>(k) == i) ? avl::BLUE : avl::YELLOW;  // Highlight left and right pointers
				}

				FillRect(x, y, barWidth, barHeight, barColor);
			}
			Display();

			// Add a delay of 3 seconds for visualization
			sf::sleep(sf::seconds(3.0f));
		}
	}

	void quicksort(std::vector<int>& arr, int low, int high)
	{
		if (low < high) {
			int pivotIndex = partition(arr, low, high);

			quicksort(arr, low, pivotIndex);
			quicksort(arr, pivotIndex + 1, high);
		}
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
		Clear(avl::BLACK);

		int maxElement = *std::max_element(arr.begin(), arr.end());

		// Calculate the width of each bar
		int barWidth = (screenWidth - 2 * margin - (arr.size() - 1) * spacing) / arr.size();

		// Calculate the height scaling factor
		float scaleFactor = static_cast<float>(screenHeight - 2 * margin) / static_cast<float>(maxElement);

		// Draw the bars
		for (size_t i = 0; i < arr.size(); ++i)
		{
			int barHeight = static_cast<int>(arr[i] * scaleFactor);

			int x = margin + i * (barWidth + spacing);
			int y = screenHeight - margin - barHeight;

			FillRect(x, y, barWidth, barHeight, avl::WHITE);
		}

		quicksort(arr, 0, arr.size() - 1);  // Start the quicksort algorithm
	}
};

int main()
{
	ExampleQuicksort demo;

	demo.SetFrameRate(60);
	demo.Render(1600, 800);
	demo.Start(false);

	return 0;
}