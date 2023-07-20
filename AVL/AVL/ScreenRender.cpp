#include "ScreenRender.h"

using namespace avl;

ScreenRender::ScreenRender() { }

void ScreenRender::Render(uint32_t width, uint32_t height, const sf::Color& color, std::function<void()> eventQueue, uint32_t bitsPerPixel)
{
    _width = width;
    _height = height;
    _bitsPerPixel = bitsPerPixel;
    //sf::Window window(sf::VideoMode(width, height, bitsPerPixel), "Window");
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height, bitsPerPixel), "Window");
    _window->clear(sf::Color::Red);

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

            eventQueue();
        }
    }
}

ScreenRender::~ScreenRender()
{

}

Vector2u ScreenRender::GetSize()
{
    return Vector2u(_width, _height);
}

void ScreenRender::EventQueue() 
{

}