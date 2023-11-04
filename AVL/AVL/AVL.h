#pragma once

#include <queue>
#include <stack>
#include <memory>
#include <cmath>

#include "ScreenRender.h"
#include "Vector2D.h"
#include "Geometry.h"
#include "TimeScale.h"
#include "InputManager.h"
#include "Utils.h"

namespace avl
{
	class AVL : public Structs
	{
	private:
		ScreenRender _screen_render;
		Geometry _geometry;
		TimeScale _timeScale;
		InputManager _inputManager;
		Grid _grid;
	public:
		AVL(); // Constructor
		~AVL(); // Destructor
	public:
		// Renders the application window
		void Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel = 32);
		// Starts the application and main game loop
		void Start(bool showFps = false);
	public: // User Override Interfaces
		// Called once on application start, used to load resources
		virtual void OnUserStart();
		// Called every frame
		virtual void OnUserUpdate();
	public: // Utility
		Vector2u GetSize();
		void Clear(const sf::Color& color);
	public: // Drawing routines
		void Display();
		// Draws a single pixel
		void Draw(int32_t x, int32_t y, const sf::Color& color = sf::Color::White);
		void Draw(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White);
		// Draws a line from (x1, y1) to (x2, y2)
		void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const sf::Color& color = sf::Color::White);
		void DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Color& color = sf::Color::White);
		// Draws a circle at (x, y)
		void DrawCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color = sf::Color::White);
		void DrawCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color = sf::Color::White);
		// Fills a circle at (x, y)
		void FillCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color = sf::Color::White);
		void FillCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color = sf::Color::White);
		// Draws a rectangle at (x, y)
		void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color = sf::Color::White);
		void DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color = sf::Color::White);
		// Fills a rectangle at (x, y)
		void FillRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color = sf::Color::White);
		void FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color = sf::Color::White);
		// Draws a triangle between points (x1, y1), (x2, y2), (x3, y3)
		void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color = sf::Color::White);
		void DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color = sf::Color::White);
		// Fills a triangle between points (x1, y1), (x2, y2), (x3, y3)
		void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color = sf::Color::White);
		void FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color = sf::Color::White);
		// Draw a text
		void DrawString(int32_t x1, int32_t y1, const std::string& text, const std::string& font = "C:\\Windows\\Fonts\\Arial.ttf", const sf::Color& color = sf::Color::White, uint32_t scale = 12);
		void DrawString(const sf::Vector2i& pos, const std::string& text, const std::string& font = "C:\\Windows\\Fonts\\Arial.ttf", const sf::Color& color = sf::Color::White, uint32_t scale = 12);
		// Draw a line
		void DrawLine(float x1, float y1, float x2, float y2);
	public: // Samples
		// Draw array
		void DrawArray(std::vector<int>& arr);
		// Draw queue
		void DrawQueue(const std::queue<int>& q);
		// Draw Stack
		void DrawStack(const std::stack<int>& s);
		// Draw Tree based on number of desired rows and columns
		void DrawTree(const std::shared_ptr<TreeNode>& root, int row, int col, int startRow = 0, int startCol = 0);
		// Draw Graph
		void DrawGraph(const std::vector<Node>& nodes, const std::vector<Edge>& edges);
	private: // Samples Utils
		void DrawTreeNode(int x, int y, int data);
		void DrawTreeLine(int x1, int y1, int x2, int y2);
	public: // Time management
		// Manage Execution time
		sf::Time GetDeltaTime();
		float GetDeltaTimeAsSeconds();
		void SetFrameRate(float targetFramerate = 30);
	public: // Screen grid
		 void CreateGrid(int row, int col);
		 void CreateGrid(int treeHeight);
	};

	// Constant color values
	const sf::Color
		RED(sf::Color::Red),
		YELLOW(sf::Color::Yellow),
		GREEN(sf::Color::Green),
		CYAN(sf::Color::Cyan),
		BLUE(sf::Color::Blue),
		BLACK(sf::Color::Black),
		WHITE(sf::Color::White),
		MAGENTA(sf::Color::Magenta);

	// Constant font filesPath
	const std::string
		ARIAL = "C:\\Windows\\Fonts\\Arial.ttf",
		TIMES_NEW_ROMAN = "C:\\Windows\\Fonts\\times.ttf",
		VERDANA = "C:\\Windows\\Fonts\\Verdana.ttf",
		CALIBRI = "C:\\Windows\\Fonts\\Calibri.ttf",
		FORTE = "C:\\Windows\\Fonts\\FORTE.ttf";
}