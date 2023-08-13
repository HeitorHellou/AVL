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
		float _deltaTime;
	protected:
		void SetDeltaTime(sf::Clock _clock);
	public:
		float GetDeltaTime();
	};
}