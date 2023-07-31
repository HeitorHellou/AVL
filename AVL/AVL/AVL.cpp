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
void AVL::Draw(int32_t x, int32_t y, const sf::Color& color = sf::Color::White) { _geometry.Draw(x, y, _screen_render._window, color); }
void AVL::Draw(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White) {}
void AVL::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const sf::Color& color = sf::Color::White) { _geometry.DrawLine(x1, y1, x2, y2, _screen_render._window, color); }
void AVL::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Color& color = sf::Color::White) {}
void AVL::DrawCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color = sf::Color::White) { _geometry.DrawCircle(x, y, radius, _screen_render._window, color); }
void AVL::DrawCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color = sf::Color::White) {}
void AVL::FillCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color = sf::Color::White) { _geometry.FillCircle(x, y, radius, _screen_render._window, color); }
void AVL::FillCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color = sf::Color::White) {}
void AVL::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color = sf::Color::White) { _geometry.DrawRect(x, y, w, h, _screen_render._window, color); }
void AVL::DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color = sf::Color::White) {}
void AVL::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color = sf::Color::White) { _geometry.FillRect(x, y, w, h, _screen_render._window, color); }
void AVL::FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color = sf::Color::White) {}
void AVL::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color = sf::Color::White) { _geometry.DrawTriangle(x1, y1, x2, y2, x3, y3, _screen_render._window, color); }
void AVL::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color = sf::Color::White) {}
void AVL::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color = sf::Color::White) { _geometry.FillTriangle(x1, y1, x2, y2, x3, y3, _screen_render._window, color); }
void AVL::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color = sf::Color::White) {}
void AVL::DrawString(int32_t x1, int32_t y1, const std::string& text, const sf::Color& color = sf::Color::White, uint32_t scale = 1) {}
void AVL::DrawString(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White, uint32_t scale = 1) {}
