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
		sf::Time _deltaTime;
	protected:
		sf::Time frameTime;
		sf::Time elapsedTime;
		int frameCount;
	protected:
		void InitFrameRateController();
		void SetDeltaTime(sf::Clock _clock);
		void CalculateElapsedTime();
		void ShowFps(sf::Clock _frameClock);
	public:
		sf::Time GetDeltaTime();
	public:
		float GetDeltaTimeAsSeconds();
		void SetFrameRate(float targetFramerate = 30);
	};
}