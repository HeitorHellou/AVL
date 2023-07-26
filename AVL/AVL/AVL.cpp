#include <memory>

#include "AVL.h"

using namespace avl;

AVL::AVL() : _screen_render{}, _geometry{} { }

AVL::~AVL() { }

void AVL::Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
	_screen_render.Render(width, height, bitsPerPixel);
}

Vector2u AVL::GetSize()
{
	return _screen_render.GetSize();
}

void AVL::Start() 
{
    OnUserCreate();

    // run the program as long as the window is open
    while (_screen_render._window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_screen_render._window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _screen_render._window->close();
        }

        OnUserUpdate();

        _screen_render.Display();
    }
}

void AVL::OnUserCreate() {}

void AVL::OnUserUpdate() {}

void AVL::Clear(const sf::Color& color)
{
    _screen_render.Clear(color);
}

// TODO

