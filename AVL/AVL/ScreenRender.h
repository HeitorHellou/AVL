#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include <functional>

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
		void Render(uint32_t width, uint32_t height, const sf::Color& color, std::function<void()> eventQueue, uint32_t bitsPerPixel = 32);
		~ScreenRender();
		Vector2u GetSize();
		void EventQueue();
	}; // class ScreenRender
} // namespace avl
