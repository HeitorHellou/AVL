#pragma once

#include "ScreenRender.h"
#include "Vector2D.h"
#include "Geometry.h"

namespace avl
{
	class AVL
	{
	private:
		ScreenRender _screen_render;
		Geometry _geometry;
	public:
		AVL();
		~AVL();
	public:
		void Render(uint32_t width, uint32_t height, const sf::Color& color, uint32_t bitsPerPixel = 32);
		Vector2u GetSize();
		void Start();
		virtual void OnUserCreate();
		virtual void OnUserUpdate();
		void Draw(float width, float height, float positionX, float positionY, const sf::Color& color = sf::Color::White);
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