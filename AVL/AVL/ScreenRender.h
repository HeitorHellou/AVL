#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2D.h"

namespace avl
{
	class ScreenRender
	{
	public:
		uint32_t _width;
		uint32_t _height;
		uint32_t _bitsPerPixel;
		std::unique_ptr<sf::RenderWindow> _window;
	public:
		ScreenRender();
		void Render(uint32_t width, uint32_t height, const sf::Color& color, uint32_t bitsPerPixel = 32);
		~ScreenRender();
		Vector2u GetSize();
	}; // class ScreenRender
} // namespace avl
