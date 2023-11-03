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
	ValidateFrameRate(targetFramerate);
	frameTime = sf::seconds(1.0f / targetFramerate);
}

void TimeScale::CalculateElapsedTime()
{
	elapsedTime += GetDeltaTime();
}

void TimeScale::ValidateFrameRate(float targetFramerate)
{
	if (targetFramerate < 0) {
		throw invalid_frame_rate();
	}
}

void TimeScale::Wait(float waitMilliseconds)
{
	sf::sleep(sf::milliseconds(waitMilliseconds));
}

void TimeScale::Wait(sf::Time waitMilliseconds)
{
	sf::sleep(waitMilliseconds);
}