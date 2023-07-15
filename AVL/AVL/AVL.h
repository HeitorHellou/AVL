#pragma once

#include "SFML/Graphics.hpp"
#include "ScreenRender.h"

namespace avl
{
	class AVL
	{
	private:
		ScreenRender window;
	public:
		AVL();
		~AVL();
		void Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel = 32);
	};
}