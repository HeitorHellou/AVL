#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2D.h"

namespace avl
{
	class ScreenRenderer
	{
	public:
		uint32_t _width;
		uint32_t _height;
		uint32_t _bitsPerPixel;
		std::unique_ptr<sf::RenderWindow> _window;
	public:
		ScreenRenderer(); // Constructor
		~ScreenRenderer(); // Destructor
		// Creates the application window
		void Renderer(uint32_t width, uint32_t height, uint32_t bitsPerPixel = 32);
	public: // Utilities
		// Returns a vector with the window size
		Vector2u GetSize();
		// Changes pplication background color
		void Clear(const sf::Color& color);
		// Displays the window
		void Display();
		// Set the window's title
		void SetTitle(const std::string& title);
		// Close the window
		void Close();
	}; // class ScreenRender
} // namespace avl
