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

//TODO
void AVL::Start() 
{
    OnUserCreate();

    // run the program as long as the window is open
    while (_screen_render._window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_screen_render._window->pollEvent(event)) // Use _window instead of window here
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _screen_render._window->close(); // Use _window instead of window here
        }

        OnUserUpdate();

        _screen_render._window->display();
    }
}

void AVL::OnUserCreate() {}

void AVL::OnUserUpdate() {}
