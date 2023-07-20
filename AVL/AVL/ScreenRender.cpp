#include "ScreenRender.h"

using namespace avl;

ScreenRender::ScreenRender() { }

ScreenRender::~ScreenRender() { }

void ScreenRender::Render(uint32_t width, uint32_t height, const sf::Color& color, uint32_t bitsPerPixel)
{
    _width = width;
    _height = height;
    _bitsPerPixel = bitsPerPixel;

    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height, bitsPerPixel), "Window");

    // run the program as long as the window is open
    while (_window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_window->pollEvent(event)) // Use _window instead of window here
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _window->close(); // Use _window instead of window here
        }

        _window->clear(color);

        _window->display();
    }
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