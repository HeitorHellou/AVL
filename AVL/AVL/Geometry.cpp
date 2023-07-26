#include "Geometry.h"
#include <SFML/Graphics.hpp>

using namespace avl;

Geometry::Geometry() { }

Geometry::~Geometry() { }

// TODO
void Geometry::Draw(int32_t x, int32_t y, const sf::Color& color = sf::Color::White) {}
void Geometry::Draw(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawCircle(int32_t x, int32_t y, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawCircle(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White) {}
void Geometry::FillCircle(int32_t x, int32_t y, const sf::Color& color = sf::Color::White) {}
void Geometry::FillCircle(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawRect(int32_t x, int32_t y, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawRect(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White) {}
void Geometry::FillRect(int32_t x, int32_t y, const sf::Color& color = sf::Color::White) {}
void Geometry::FillRect(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color = sf::Color::White) {}
void Geometry::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color = sf::Color::White) {}
void Geometry::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawString(int32_t x1, int32_t y1, const std::string& text, const sf::Color& color = sf::Color::White, uint32_t scale = 1) {}
void Geometry::DrawString(const sf::Vector2i& pos, const sf::Color& color = sf::Color::White, uint32_t scale = 1) {}
