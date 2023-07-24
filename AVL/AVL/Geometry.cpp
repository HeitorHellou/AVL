#include "Geometry.h"
#include <SFML/Graphics.hpp>

using namespace avl;

Geometry::Geometry() { }

Geometry::~Geometry() { }

sf::RectangleShape Geometry::DrawSquare(float width, float height, float positionX, float positionY, const sf::Color& color)
{
    sf::RectangleShape square(sf::Vector2f(width, height));
    square.setFillColor(color);
    square.setPosition(positionX, positionY);

    return square;
}

sf::CircleShape Geometry::DrawCircle(float radius, float positionX, float positionY, const sf::Color& color)
{ 
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(positionX, positionY);

    return circle;
}

// ** DISCUTIR PARÂMETROS ** //
sf::ConvexShape Geometry::DrawTriangle(const sf::Color& color)
{ 
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(500, 100));
    triangle.setPoint(1, sf::Vector2f(600, 100));
    triangle.setPoint(2, sf::Vector2f(550, 200));
    triangle.setFillColor(color);

    return triangle;
}
