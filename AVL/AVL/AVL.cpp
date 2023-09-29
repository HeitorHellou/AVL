#include <memory>
#include "AVL.h"

using namespace avl;

AVL::AVL() : _screen_render{}, _geometry{}, _timeScale{}, _inputManager{} { }

AVL::~AVL() { }

void AVL::Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
	_screen_render.Render(width, height, bitsPerPixel);
}

Vector2u AVL::GetSize()
{
	return _screen_render.GetSize();
}

void AVL::Start(bool showFps)
{
    sf::Clock globalDeltaTimeClock;
    sf::Clock frameClock;
    sf::Clock frameCalcClock;

    _timeScale.InitFrameRateController();
    OnUserStart();

    // run the program as long as the window is open
    while (_screen_render._window->isOpen())
    {
        _timeScale.SetDeltaTime(globalDeltaTimeClock);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_screen_render._window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _screen_render._window->close();
            else if (event.type == sf::Event::MouseWheelScrolled)
                _inputManager.UpdateMouseWheelDelta(event);
        }

        _timeScale.elapsedTime += frameCalcClock.restart();

        // Lock frame rate
        while (_timeScale.elapsedTime >= _timeScale.frameTime)
        {
            OnUserUpdate();

            _timeScale.frameCount++;
            if (showFps)
            {
                if (frameClock.getElapsedTime().asSeconds() >= 1.0f) {
                    float fps = _timeScale.frameCount / frameClock.getElapsedTime().asSeconds();
                    std::cout << "FPS: " << fps << std::endl;

                    _timeScale.frameCount = 0;
                    frameClock.restart();
                }
            }
            _timeScale.elapsedTime -= _timeScale.frameTime;
        }

        _screen_render.Display();

        sf::sleep(_timeScale.frameTime - _timeScale.elapsedTime);
    }
}

void AVL::OnUserStart() {}

void AVL::OnUserUpdate() {}

void AVL::Clear(const sf::Color& color)
{
    _screen_render.Clear(color);
}

void AVL::Display()
{
    _screen_render.Display();
}

void AVL::Draw(int32_t x, int32_t y, const sf::Color& color) 
{ 
    _geometry.Draw(x, y, _screen_render._window, color); 
}

void AVL::Draw(const sf::Vector2i& pos, const sf::Color& color) 
{
    _geometry.Draw(pos.x, pos.y, _screen_render._window, color);
}

void AVL::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const sf::Color& color) 
{ 
    _geometry.DrawLine(x1, y1, x2, y2, _screen_render._window, color); 
}

void AVL::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Color& color) 
{
    _geometry.DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, _screen_render._window, color);
}

void AVL::DrawCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color) 
{ 
    _geometry.DrawCircle(x, y, radius, _screen_render._window, color); 
}

void AVL::DrawCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color) 
{
    _geometry.DrawCircle(pos.x, pos.y, radius, _screen_render._window, color);
}

void AVL::FillCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color) 
{ 
    _geometry.FillCircle(x, y, radius, _screen_render._window, color); 
}

void AVL::FillCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color) 
{
    _geometry.FillCircle(pos.x, pos.y, radius, _screen_render._window, color);
}

void AVL::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color) 
{ 
    _geometry.DrawRect(x, y, w, h, _screen_render._window, color); 
}

void AVL::DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color) 
{
    _geometry.DrawRect(pos.x, pos.y, w, h, _screen_render._window, color);
}

void AVL::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color) 
{ 
    _geometry.FillRect(x, y, w, h, _screen_render._window, color); 
}

void AVL::FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color) 
{
    _geometry.FillRect(pos.x, pos.y, w, h, _screen_render._window, color);
}

void AVL::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color) 
{ 
    _geometry.DrawTriangle(x1, y1, x2, y2, x3, y3, _screen_render._window, color); 
}

void AVL::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color) 
{
    _geometry.DrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, _screen_render._window, color);
}

void AVL::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color) 
{ 
    _geometry.FillTriangle(x1, y1, x2, y2, x3, y3, _screen_render._window, color); 
}

void AVL::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color) 
{
    _geometry.FillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, _screen_render._window, color);
}

void AVL::DrawString(int32_t x1, int32_t y1, const std::string& text, const std::string& font, const sf::Color& color, uint32_t scale)
{
    _geometry.DrawString(x1, y1, text, font, _screen_render._window, color, scale);
}

void AVL::DrawString(const sf::Vector2i& pos, const std::string& text, const std::string& font, const sf::Color& color, uint32_t scale) 
{
    _geometry.DrawString(pos.x, pos.y, text, font, _screen_render._window, color, scale);
}

void AVL::DrawLine(float x1, float y1, float x2, float y2)
{
    _geometry.DrawLine(x1, y1, x2, y2, _screen_render._window);
}

sf::Time AVL::GetDeltaTime()
{
    return _timeScale.GetDeltaTime();
}

float AVL::GetDeltaTimeAsSeconds() 
{
    return _timeScale.GetDeltaTimeAsSeconds();
}

void AVL::SetFrameRate(float targetFramerate) 
{
    _timeScale.SetFrameRate(targetFramerate);
}

void AVL::DrawTree() 
{
    
}
