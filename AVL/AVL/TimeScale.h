#pragma once

#include <SFML/Graphics.hpp>

namespace avl
{
	class TimeScale
	{
	public:
		TimeScale(); // Constructor
		~TimeScale(); // Destructor
	private:
		// Stores current deltaTime
		sf::Time _deltaTime;
	protected: // Only AVL class has access
		sf::Time frameTime;
		sf::Time elapsedTime;
		int frameCount;
	protected: // Only AVL class has access
		// Init frame rate calculation
		void InitFrameRateController();
		// Set the current delta Time
		void SetDeltaTime(sf::Clock _clock);
		// Calculate current elapsed time
		void CalculateElapsedTime();
	public:
		// Get delta time as SFML time object
		sf::Time GetDeltaTime();
		// Get delta time calculated as seconds
		float GetDeltaTimeAsSeconds();
		// Set target frame rate
		void SetFrameRate(float targetFramerate = 30);
	};
}