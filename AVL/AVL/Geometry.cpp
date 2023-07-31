#include "Geometry.h"
#include <SFML/Graphics.hpp>

using namespace avl;

Geometry::Geometry() { }

Geometry::~Geometry() { }

// TODO
void Geometry::Draw(int32_t x, int32_t y, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White)
{
	sf::Vertex pixel(sf::Vector2f(x, y), color);
	target->draw(&pixel, 1, sf::Points);
}
void Geometry::Draw(const sf::Vector2i& pos, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) 
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(x1, y1), color),
		sf::Vertex(sf::Vector2f(x2, y2), color)
	};

	sf::VertexArray lineVertices(sf::Lines, 2);
	lineVertices[0] = line[0];
	lineVertices[1] = line[1];

	target->draw(lineVertices);
}
void Geometry::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawCircle(int32_t x, int32_t y, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) 
{
	sf::CircleShape circle;
	circle.setPosition(x, y);
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(2.0f);
	circle.setOutlineColor(color);

	target->draw(circle);
}
void Geometry::DrawCircle(const sf::Vector2i& pos, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::FillCircle(int32_t x, int32_t y, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White)
{
	sf::CircleShape circle;
	circle.setPosition(x, y);
	circle.setRadius(radius);
	circle.setFillColor(color);

	target->draw(circle);
}
void Geometry::FillCircle(const sf::Vector2i& pos, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) 
{
	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(2.0f);
	rect.setOutlineColor(color);

	target->draw(rect);
}
void Geometry::DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) 
{
	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	rect.setFillColor(color);
	rect.setOutlineThickness(0.0f);

	target->draw(rect);
}
void Geometry::FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) 
{
	sf::VertexArray lines(sf::Lines);

	lines.append(sf::Vertex(sf::Vector2f(x1, y1), color));
	lines.append(sf::Vertex(sf::Vector2f(x2, y2), color));
	lines.append(sf::Vertex(sf::Vector2f(x2, y2), color));
	lines.append(sf::Vertex(sf::Vector2f(x3, y3), color));
	lines.append(sf::Vertex(sf::Vector2f(x3, y3), color));
	lines.append(sf::Vertex(sf::Vector2f(x1, y1), color));

	target->draw(lines);
}
void Geometry::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) 
{
	sf::ConvexShape triangle;

	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(x1, y1));
	triangle.setPoint(1, sf::Vector2f(x2, y2));
	triangle.setPoint(2, sf::Vector2f(x3, y3));

	triangle.setFillColor(color);

	target->draw(triangle);
}
void Geometry::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White) {}
void Geometry::DrawString(int32_t x1, int32_t y1, const std::string& text, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White, uint32_t scale = 1) {}
void Geometry::DrawString(const sf::Vector2i& pos, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White, uint32_t scale = 1) {}
