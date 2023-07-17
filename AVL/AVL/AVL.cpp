#include "AVL.h"

using namespace avl;

AVL::AVL() { }

AVL::~AVL() { }

void AVL::Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
	_window = ScreenRender(width, height, bitsPerPixel);
}

Vector2u AVL::GetSize()
{
	return _window.GetSize();
}

void AVL::SetColor(sf::Color color)
{
	
}