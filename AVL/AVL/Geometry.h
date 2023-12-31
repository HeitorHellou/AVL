#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include "AVLExceptions.h"

namespace avl 
{
	class Geometry 
	{
	public:
		Geometry();
		~Geometry();
	public: // Drawing utilities
		// Draws a single pixel
		void Draw(int32_t x, int32_t y, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void Draw(const sf::Vector2i& pos, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Draws a line from (x1, y1) to (x2, y2)
		void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Draws a circle at (x, y)
		void DrawCircle(int32_t x, int32_t y, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void DrawCircle(const sf::Vector2i& pos, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Fills a circle at (x, y)
		void FillCircle(int32_t x, int32_t y, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void FillCircle(const sf::Vector2i& pos, int32_t radius, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Draws a rectangle at (x, y)
		void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Fills a rectangle at (x, y)
		void FillRect(int32_t x, int32_t y, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Draws a triangle between points (x1, y1), (x2, y2), (x3, y3)
		void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Fills a triangle between points (x1, y1), (x2, y2), (x3, y3)
		void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		void FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White);
		// Draw a text
		void DrawString(int32_t x1, int32_t y1, const std::string& text, const std::string& fontPath, std::unique_ptr<sf::RenderWindow>& target, const sf::Color& color = sf::Color::White, uint32_t scale = 12);
		void DrawString(const sf::Vector2i& pos, const std::string& text, std::unique_ptr<sf::RenderWindow>& target, const std::string& fontPath, const sf::Color& color, uint32_t scale);
		// Draw a line
		void DrawLine(float x1, float y1, float x2, float y2, std::unique_ptr<sf::RenderWindow>& target);
	private:
		// Basic validation for all methods
		void BasicValidation(int32_t x, int32_t y, std::unique_ptr<sf::RenderWindow>& target);
		void BasicValidation(int32_t x, int32_t y, uint32_t scale, std::unique_ptr<sf::RenderWindow>& target);
		void BasicValidation(int32_t x1, int32_t y1, int32_t x2, int32_t y2, std::unique_ptr<sf::RenderWindow>& target);
		void BasicValidation(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, std::unique_ptr<sf::RenderWindow>& target);
		// Validation for circle methods
		void CircleValidation(int32_t radius);
		// Validation for rect methods
		void RectValidation(int32_t w, int32_t h);
	};
}
