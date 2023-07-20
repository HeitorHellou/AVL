#include <memory>

#include "AVL.h"

using namespace avl;

AVL::AVL() : _screen_render{} { }

AVL::~AVL() { }

void AVL::Render(uint32_t width, uint32_t height, const sf::Color& color, uint32_t bitsPerPixel)
{
	_screen_render.Render(width, height, color, bitsPerPixel);
}

Vector2u AVL::GetSize()
{
	return _screen_render.GetSize();
}