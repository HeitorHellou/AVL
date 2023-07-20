#pragma once

#include "ScreenRender.h"
#include "Vector2D.h"
	

namespace avl
{
	class AVL
	{
	private:
		ScreenRender _screen_render;
	public:
		AVL();
		~AVL();
	public:
		void Render(uint32_t width, uint32_t height, const sf::Color& color, std::function<void()> eventQueue, uint32_t bitsPerPixel = 32);
		Vector2u GetSize();
	};

	const sf::Color
		RED(sf::Color::Red),
		YELLOW(sf::Color::Yellow),
		GREEN(sf::Color::Green),
		CYAN(sf::Color::Cyan),
		BLUE(sf::Color::Blue),
		BLACK(sf::Color::Black),
		WHITE(sf::Color::White),
		MAGENTA(sf::Color::Magenta);
}