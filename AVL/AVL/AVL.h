#pragma once

#include "ScreenRender.h"
#include "Vector2D.h"
#include "Geometry.h"

namespace avl
{
	class AVL
	{
	private:
		ScreenRender _screen_render;
		Geometry _geometry;
	public:
		AVL(); // Constructor
		~AVL(); // Destructor
	public:
		// Renders the application window
		void Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel = 32);
		void Start();
	public: // User Override Interfaces
		// Called once on application start, used to load resources
		virtual void OnUserCreate();
		// Called every frame
		virtual void OnUserUpdate();
	public: // Utility
		Vector2u GetSize();
		void Clear(const sf::Color& color);
	public: // Drawing routines
		
	};

	// Constant color values
	const sf::Color
		RED(sf::Color::Red),
		YELLOW(sf::Color::Yellow),
		GREEN(sf::Color::Green),
		CYAN(sf::Color::Cyan),
		BLUE(sf::Color::Blue),
		BLACK(sf::Color::Black),
		WHITE(sf::Color::White),
		MAGENTA(sf::Color::Magenta);
}