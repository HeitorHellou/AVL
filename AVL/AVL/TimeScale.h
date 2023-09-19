#pragma once

#include <SFML/Graphics.hpp>
#include "AVLExceptions.h";

namespace avl
{
	class TimeScale
	{
	public:
		TimeScale(); // Constructor
		~TimeScale(); // Destructor
	public: // Only AVL class has access
		sf::Time frameTime;
		sf::Time elapsedTime;
		int frameCount;
	private:
		// Stores current deltaTime
		sf::Time _deltaTime;
	public: // Only AVL class has access
		// Init frame rate calculation
		void InitFrameRateController();
		// Set the current delta Time
		void SetDeltaTime(sf::Clock _clock);
		// Calculate current elapsed time
		void CalculateElapsedTime();
		// Get delta time as SFML time object
		sf::Time GetDeltaTime();
		// Get delta time calculated as seconds
		float GetDeltaTimeAsSeconds();
		// Set target frame rate
		void SetFrameRate(float targetFramerate = 30);
	private:
		void ValidateFrameRate(float targetFramerate);
	};
}