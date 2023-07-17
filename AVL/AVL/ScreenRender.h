#pragma once

#include <SFML/Window.hpp>
#include "Vector2D.h"

namespace avl
{
	class ScreenRender
	{
	public:
		uint32_t _width;
		uint32_t _height;
		uint32_t _bitsPerPixel;
	public:
		ScreenRender();
		ScreenRender(uint32_t width, uint32_t height, uint32_t bitsPerPixel = 32);
		~ScreenRender();
		Vector2u GetSize();
	}; // class ScreenRender
} // namespace avl
