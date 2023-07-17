#pragma once

#include "SFML/Graphics.hpp"
#include "ScreenRender.h"
#include "Vector2D.h"

namespace avl
{
	class AVL
	{
	private:
		ScreenRender _window;
	public:
		AVL();
		~AVL();
	public:
		void Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel = 32);
		Vector2u GetSize();
		void SetColor(sf::Color color);
	};
}