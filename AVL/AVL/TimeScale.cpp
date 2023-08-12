#include "TimeScale.h"

using namespace avl;

TimeScale::TimeScale() { }

TimeScale::~TimeScale() { }

void TimeScale::SetDeltaTime(sf::Clock clock) 
{
	_deltaTime = clock.restart().asSeconds();
}

float TimeScale::GetDeltaTime()
{
	return _deltaTime;
}
