#pragma once

#include <SFML/Graphics.hpp>

namespace avl 
{
	class Geometry 
	{
	public:
		Geometry();
		~Geometry();
		sf::RectangleShape DrawSquare(float width, float height, float positionX, float positionY, const sf::Color& color = sf::Color::White);
		sf::CircleShape DrawCircle(float radius, float positionX, float positionY, const sf::Color& color = sf::Color::White);
		sf::ConvexShape DrawTriangle(const sf::Color& color = sf::Color::White);
	};
}
