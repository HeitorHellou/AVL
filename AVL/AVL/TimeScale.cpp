#include "TimeScale.h"
#include <iostream>

using namespace avl;

TimeScale::TimeScale() { }

TimeScale::~TimeScale() { }

void TimeScale::SetDeltaTime(sf::Clock clock)
{
	_deltaTime = clock.restart();
}

sf::Time TimeScale::GetDeltaTime()
{
	return _deltaTime;
}

float TimeScale::GetDeltaTimeAsSeconds()
{
	return _deltaTime.asSeconds();
}

void TimeScale::InitFrameRateController() 
{
	elapsedTime = sf::Time::Zero;
	frameCount = 0;
}

void TimeScale::SetFrameRate(float targetFramerate) {
	frameTime = sf::seconds(1.0f / targetFramerate);
}

void TimeScale::CalculateElapsedTime()
{
	elapsedTime += GetDeltaTime();
}

void TimeScale::ShowFps(sf::Clock _frameClock)
{
	if (_frameClock.getElapsedTime().asSeconds() >= 1.0f) {
		float fps = frameCount / _frameClock.getElapsedTime().asSeconds();
		std::cout << "FPS: " << fps << std::endl;

		frameCount = 0;
		_frameClock.restart();
	}
}