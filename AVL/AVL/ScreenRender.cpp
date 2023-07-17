#include "ScreenRender.h"

using namespace avl;

ScreenRender::ScreenRender() { }

ScreenRender::ScreenRender(uint32_t width, uint32_t height, uint32_t bitsPerPixel): _width{ width }, _height{ height }, _bitsPerPixel{ bitsPerPixel }
{
	sf::Window window(sf::VideoMode(width, height, bitsPerPixel), "Window");

    //// run the program as long as the window is open
    //while (window.isOpen())
    //{
    //    // check all the window's events that were triggered since the last iteration of the loop
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        // "close requested" event: we close the window
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }
    //}
}

ScreenRender::~ScreenRender()
{

}

Vector2u ScreenRender::GetSize()
{
    return Vector2u(_width, _height);
}