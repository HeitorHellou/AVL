
<div align="center">
  <h3 align="center">Algorithms Visualization Library</h3>

  <p align="center">
    [A brief description of what this project does and who it's for]
    <br />
    <a href="https://github.com/HeitorHellou/AVL/wiki"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/HeitorHellou/AVL">View Demo</a>
    ·
    <a href="https://github.com/HeitorHellou/AVL/issues">Report Bug</a>
    ·
    <a href="https://github.com/HeitorHellou/AVL/issues">Request Feature</a>
  </p>
</div>

## About the Project
<!-- LEO explicar aqui oq o nosso projeto é e o objetivo dele ser criado, da uma olhada no nosso doc do tcc pra fazer essa parte. DA PRA DEIXAR UM PARAGRAFO PARA CADA PARTE AQUI  -->
<!-- LEO explicar aqui oq o nosso projeto faz, tipo ele desenha..., ele recebe input do usuario...  -->
Full description here.

## Built With

The tools used to bootstrap this project were:

[![C++][Cplus.logo]][Cplus.com]
[![SFML][SFML.logo]][SFML.com]
[![Visual Studio][VisualStudio.logo]][VisualStudio.logo]

## Getting Started

### Prerequisites

To run this project on your local desktop, you must have Microsoft Visual Studio installed and with its C++ support set. You'll need to install and setup SFML 2.5.1 as well, but we will explain how to do it in the next topics.

### Project setup

(1) Clone the repo
   ```sh
   git clone https://github.com/HeitorHellou/AVL.git
   ```

### SFML instalation

Follow the steps below to install and setup SFML 2.5.1 in your local environment. You can follow this video as well: [How to setup SFML in Visual Studio in 5 minutes. Fully Explained].

(1) Open SFML download page <a href="https://www.sfml-dev.org/download/sfml/2.5.1/" target="_blank"><strong>here</strong></a>

(2) Download the Visual C++ 15 (2017) - 64-bit version and save it locally.

![image](https://github.com/HeitorHellou/AVL/assets/61805977/84539043-98a6-4ff0-83eb-312841df443a)

(3) Open the SFML folder and copy the <strong>include</strong> and <strong>lib</strong> folder into the project folder. Must be along with the project sln file.

![image](https://github.com/HeitorHellou/AVL/assets/61805977/e81112ee-6eab-410a-a036-9b4514475ce4)
![image](https://github.com/HeitorHellou/AVL/assets/61805977/de4e1db8-168e-4081-9a48-dad525059289)

(4) Open your Visual Studio. After its open, don't forget to set the target architecture to x64.

![image](https://github.com/HeitorHellou/AVL/assets/61805977/9367e368-070f-4285-b8a1-d361823089c6)

(5) Build the project in Debug and Release mode.

(6) Go to the SFML folder again and copy the dll files with '-d' in their names from bin folder. Paste these files in your project's Debug folder.

![image](https://github.com/HeitorHellou/AVL/assets/61805977/5c5bdac9-ba47-4abd-a6fe-72b46f321cbd)

(7) In the SFML folder as well, open the bin folder again. But now copy the dll files without '-d' in their names and paste in your project's Release folder.

(8) Go back to Visual Studio. In the project hierarchy, right click in the project and select properties.

![image](https://github.com/HeitorHellou/AVL/assets/61805977/5ed669fb-e539-4615-bac2-f30f13ba30df)

(9) Make sure to select 'All Configurations' and 'All Platforms' in the header menu.

(10) In the left corner menu go to C/C++ and General. In 'Additional Include Directories' add your project's include folder path. Like the example below:
```sh
   $(SolutionDir)\include
   ```

![image](https://github.com/HeitorHellou/AVL/assets/61805977/6b1fdf92-75a3-41e8-b1eb-c92316b3a167)

(11) Again in the left corner menu go to Linker and General. In 'Additional Library Directories' add your project's lib folder path. Like the example below:
```sh
   $(SolutionDir)\lib
   ```

![image](https://github.com/HeitorHellou/AVL/assets/61805977/d9331877-08fd-4dbd-bcb6-85a750a10296)

(12) Still in the Linker configs. In 'Additional Dependencies' add for Debug configuration:
```sh
   sfml-system-d.lib;
   sfml-window-d.lib;
   sfml-graphics-d.lib;
   ```

![image](https://github.com/HeitorHellou/AVL/assets/61805977/01d187fe-6a00-40b6-ac61-5c31038a32e1)

(13) Still in the Linker configs. In 'Additional Dependencies' add for Release configuration:
```sh
   sfml-system.lib;
   sfml-window.lib;
   sfml-graphics.lib;
   ```

(14) Therefore, click in Apply.

(15) Try to build the project and run a simple test:
```sh
    #include <iostream>
    #include "AVL.h"

    class Teste : public avl::AVL 
    {
    public:
        virtual void OnUserStart()
        {
        }

        virtual void OnUserUpdate()
        {
            DrawCircle(250, 250, 150);
            DrawString(350, 150, "Well done, it worked!!", avl::TIMES_NEW_ROMAN, sf::Color::White, 25);
        }
    };

    int main()
    {
        Teste teste;
        teste.SetFrameRate(60);
        teste.Render(800, 800);

        try 
        {
            teste.Start();
        }
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        return 0;
    }
   ```

Result:
![image](https://github.com/HeitorHellou/AVL/assets/61805977/c74e0f78-30d9-49be-9cf1-a7c4124dab08)

### Visual Studio Project Configuration

Update your project .vcxproj file with the following:
```
  <ItemGroup>
    <ClInclude Include="AVL.h" />
    <ClInclude Include="AVLExceptions.h" />
    <ClInclude Include="Geometry.h" />
    <ClInclude Include="TimeScale.h" />
    <ClInclude Include="InputManager.h" />
    <ClInclude Include="ScreenRender.h" />
    <ClInclude Include="Vector2D.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="AVL.cpp" />
    <ClCompile Include="Geometry.cpp" />
    <ClCompile Include="InputManager.cpp" />
    <ClCompile Include="main.cpp" />
    <ClCompile Include="ScreenRender.cpp" />
    <ClCompile Include="TimeScale.cpp" />
  </ItemGroup>
```
Update your project .vcxproj.filters with the following:
```
<ItemGroup>
    <ClInclude Include="AVL.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="ScreenRender.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="Vector2D.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="Geometry.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="TimeScale.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="InputManager.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="AVlExceptions.h">
      <Filter>Header Files</Filter>
    </ClInclude>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="main.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="ScreenRender.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="AVL.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="Geometry.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="TimeScale.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="InputManager.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
```

## Usage

<ol>
  <li>Include the header file "AVL.h" from a source file</li>
  <li>Derive a sub-class from avl::AVL</li>
  <li>Optionally override the OnUserStart() method</li>
  <li>Override the OnUserUpdate() method</li>
  <li>Create a instance of your derived class, typically on main</li>
  <li>Call the Render() method and specify the screen dimensions</li>
  <li>Call the Start() method to run your application</li>
</ol>

### Example AVL "QuickSort"

```sh
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
   ```

## License

Describe license here.

## Authors

- Heitor Hellou 
- Leonardo Muller
- Marco Pagno
- Othon Valentim

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[SFML.com]: https://www.sfml-dev.org
[SFML.logo]: https://www.sfml-dev.org/download/goodies/sfml-logo.svg
[Cplus.com]: https://learn.microsoft.com/pt-br/cpp/cpp/?view=msvc-170
[Cplus.logo]: https://seeklogo.com/images/C/c-logo-1B1817C041-seeklogo.com.png
[VisualStudio.com]: https://visualstudio.microsoft.com/pt-br/ 
[VisualStudio.logo]: https://seeklogo.com/images/V/visual-studio-icon-2022-logo-8E86B4B761-seeklogo.com.png
[How to setup SFML in Visual Studio in 5 minutes. Fully Explained]: https://www.youtube.com/watch?v=lFzpkvrscs4
