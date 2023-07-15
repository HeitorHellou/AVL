#include "AVL.h"

using namespace avl;

AVL::AVL() { }

AVL::~AVL() { }

void AVL::Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
	window = ScreenRender(width, height, bitsPerPixel);
}