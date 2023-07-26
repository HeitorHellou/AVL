#include "ScreenRender.h"

using namespace avl;

ScreenRender::ScreenRender() { }

ScreenRender::~ScreenRender() { }

void ScreenRender::Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
    _width = width;
    _height = height;
    _bitsPerPixel = bitsPerPixel;

    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height, bitsPerPixel), "Window");
}

void ScreenRender::Clear(const sf::Color& color)
{
    _window->clear(color);
}

void ScreenRender::Display()
{
    _window->display();
}

Vector2u ScreenRender::GetSize()
{
    return Vector2u(_width, _height);
}

void ScreenRender::SetTitle(const std::string& title) 
{
    _window->setTitle(title);
}

void ScreenRender::Close()
{
    _window->close();
}

