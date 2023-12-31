#include "Geometry.h"
#include <SFML/Graphics.hpp>

using namespace avl;

Geometry::Geometry() { }

Geometry::~Geometry() { }

// DRAW METHODS
void Geometry::Draw(int32_t x, int32_t y, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color)
{
	BasicValidation(x, y, target);

	sf::Vertex pixel(sf::Vector2f(x, y), color);
	target->draw(&pixel, 1, sf::Points);
}

void Geometry::Draw(const sf::Vector2i& pos, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos.x, pos.y, target);

	sf::Vertex pixel(sf::Vector2f(pos.x, pos.y), color);
	target->draw(&pixel, 1, sf::Points);
}

void Geometry::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(x1, y1, x2, y2, target);

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

void Geometry::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos1.x, pos1.y, pos2.x, pos2.y, target);

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(pos1.x, pos1.y), color),
		sf::Vertex(sf::Vector2f(pos2.x, pos2.y), color)
	};

	sf::VertexArray lineVertices(sf::Lines, 2);
	lineVertices[0] = line[0];
	lineVertices[1] = line[1];

	target->draw(lineVertices);
}

void Geometry::DrawCircle(int32_t x, int32_t y, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(x, y, target);
	CircleValidation(radius);

	sf::CircleShape circle;
	circle.setPosition(x, y);
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(2.0f);
	circle.setOutlineColor(color);

	target->draw(circle);
}

void Geometry::DrawCircle(const sf::Vector2i& pos, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos.x, pos.y, target);
	CircleValidation(radius);

	sf::CircleShape circle;
	circle.setPosition(pos.x, pos.y);
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(2.0f);
	circle.setOutlineColor(color);

	target->draw(circle);
}

void Geometry::FillCircle(int32_t x, int32_t y, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color)
{
	BasicValidation(x, y, target);
	CircleValidation(radius);

	sf::CircleShape circle;
	circle.setPosition(x, y);
	circle.setRadius(radius);
	circle.setFillColor(color);

	target->draw(circle);
}

void Geometry::FillCircle(const sf::Vector2i& pos, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos.x, pos.y, target);
	CircleValidation(radius);

	sf::CircleShape circle;
	circle.setPosition(pos.x, pos.y);
	circle.setRadius(radius);
	circle.setFillColor(color);

	target->draw(circle);
}

void Geometry::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(x, y, target);
	RectValidation(w, h);

	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(2.0f);
	rect.setOutlineColor(color);

	target->draw(rect);
}

void Geometry::DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos.x, pos.y, target);
	RectValidation(w, h);

	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(pos.x, pos.y);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(2.0f);
	rect.setOutlineColor(color);

	target->draw(rect);
}

void Geometry::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(x, y, target);
	RectValidation(w, h);

	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	rect.setFillColor(color);
	rect.setOutlineThickness(0.0f);

	target->draw(rect);
}

void Geometry::FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos.x, pos.y, target);
	RectValidation(w, h);

	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(pos.x, pos.y);
	rect.setFillColor(color);
	rect.setOutlineThickness(0.0f);

	target->draw(rect);
}

void Geometry::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(x1, y1, x2, y2, x3, y3, target);

	sf::VertexArray lines(sf::Lines);

	lines.append(sf::Vertex(sf::Vector2f(x1, y1), color));
	lines.append(sf::Vertex(sf::Vector2f(x2, y2), color));
	lines.append(sf::Vertex(sf::Vector2f(x2, y2), color));
	lines.append(sf::Vertex(sf::Vector2f(x3, y3), color));
	lines.append(sf::Vertex(sf::Vector2f(x3, y3), color));
	lines.append(sf::Vertex(sf::Vector2f(x1, y1), color));

	target->draw(lines);
}

void Geometry::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, target);

	sf::VertexArray lines(sf::Lines);

	lines.append(sf::Vertex(sf::Vector2f(pos1.x, pos1.y), color));
	lines.append(sf::Vertex(sf::Vector2f(pos2.x, pos2.y), color));
	lines.append(sf::Vertex(sf::Vector2f(pos2.x, pos2.y), color));
	lines.append(sf::Vertex(sf::Vector2f(pos3.x, pos3.y), color));
	lines.append(sf::Vertex(sf::Vector2f(pos3.x, pos3.y), color));
	lines.append(sf::Vertex(sf::Vector2f(pos1.x, pos1.y), color));

	target->draw(lines);
}

void Geometry::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(x1, y1, x2, y2, x3, y3, target);

	sf::ConvexShape triangle;

	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(x1, y1));
	triangle.setPoint(1, sf::Vector2f(x2, y2));
	triangle.setPoint(2, sf::Vector2f(x3, y3));

	triangle.setFillColor(color);

	target->draw(triangle);
}

void Geometry::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color) 
{
	BasicValidation(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, target);

	sf::ConvexShape triangle;

	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(pos1.x, pos1.y));
	triangle.setPoint(1, sf::Vector2f(pos2.x, pos2.y));
	triangle.setPoint(2, sf::Vector2f(pos3.x, pos3.y));

	triangle.setFillColor(color);

	target->draw(triangle);
}

void Geometry::DrawString(int32_t x1, int32_t y1, const std::string& text, const std::string& fontPath, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color, uint32_t scale)
{
	BasicValidation(x1, y1, scale, target);

	sf::Font _font;
	if (!_font.loadFromFile(fontPath)) 
	{
		return;
	}

	sf::Text _text;
	_text.setString(text);
	_text.setFont(_font);
	_text.setCharacterSize(scale);
	_text.setFillColor(color);
	_text.setPosition(x1, y1);

	target->draw(_text);
}

void Geometry::DrawString(const sf::Vector2i& pos, const std::string& text, std::unique_ptr<sf::RenderWindow>& target, const std::string& fontPath, const sf::Color& color, uint32_t scale) 
{
	BasicValidation(pos.x, pos.y, scale, target);

	sf::Font _font;
	if (!_font.loadFromFile(fontPath))
	{
		return;
	}

	sf::Text _text;
	_text.setString(text);
	_text.setFont(_font);
	_text.setCharacterSize(scale);
	_text.setFillColor(color);
	_text.setPosition(pos.x, pos.y);

	target->draw(_text);
}

void Geometry::DrawLine(float x1, float y1, float x2, float y2, std::unique_ptr<sf::RenderWindow>& target)
{
	 sf::Vertex lines[] = {
		  sf::Vertex(sf::Vector2f(x1, y1)),
		  sf::Vertex(sf::Vector2f(x2, y2))
	 };

	 target->draw(lines, sizeof(lines), sf::Lines);
}

// VALIDATIONS METHODS
void Geometry::BasicValidation(int32_t x, int32_t y, std::unique_ptr<sf::RenderWindow>& target)
{
	if (target == NULL)
	{
		throw target_renderWindow_error();
	}
	if (x < 0 || y < 0)
	{
		throw invalid_position();
	}
}

void Geometry::BasicValidation(int32_t x, int32_t y, uint32_t scale, std::unique_ptr<sf::RenderWindow>& target)
{
	BasicValidation(x, y, target);
	if (scale < 0 || scale > 50) 
	{
		throw invalid_scale();
	}
}

void Geometry::BasicValidation(int32_t x1, int32_t y1, int32_t x2, int32_t y2, std::unique_ptr<sf::RenderWindow>& target)
{
	if (target == NULL)
	{
		throw target_renderWindow_error();
	}
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
	{
		throw invalid_position();
	}
}

void Geometry::BasicValidation(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target)
{
	if (target == NULL)
	{
		throw target_renderWindow_error();
	}
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x3 < 0 || y3 < 0)
	{
		throw invalid_position();
	}
}

void Geometry::RectValidation(int32_t w, int32_t h)
{
	if (w < 0 || h < 0)
	{
		throw invalid_width_height();
	}
}

void Geometry::CircleValidation(int32_t radius)
{
	if (radius < 0)
	{
		throw invalid_radius();
	}
}
