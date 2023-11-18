#include "ScreenRenderer.h"

using namespace avl;

ScreenRenderer::ScreenRenderer() { }

ScreenRenderer::~ScreenRenderer() { }

void ScreenRenderer::Renderer(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
    _width = width;
    _height = height;
    _bitsPerPixel = bitsPerPixel;

    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height, bitsPerPixel), "Window");
}

void ScreenRenderer::Clear(const sf::Color& color)
{
    _window->clear(color);
}

void ScreenRenderer::Display()
{
    _window->display();
}

Vector2u ScreenRenderer::GetSize()
{
    return Vector2u(_width, _height);
}

void ScreenRenderer::SetTitle(const std::string& title) 
{
    _window->setTitle(title);
}

void ScreenRenderer::Close()
{
    _window->close();
}
