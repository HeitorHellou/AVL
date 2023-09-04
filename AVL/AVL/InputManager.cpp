#include "InputManager.h"

using namespace avl;

// Get State of key
SButton InputManager::GetKey(Key k) const 
{
	return pKeyboardState[static_cast<int>(k)];
}

// Get State of mouse button
SButton InputManager::GetMouse(uint32_t b) const 
{
	return pMouseState[b];
}

// Get Mouse X coordinate
int32_t InputManager::GetMouseX() const 
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	return mousePosition.x;
}

// Get Mouse Y coordinate
int32_t InputManager::GetMouseY() const 
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	return mousePosition.y;
}

void InputManager::UpdateMouseWheelDelta(const sf::Event& event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		nMouseWheelDelta = event.mouseWheelScroll.delta;
	}
}

// Get Mouse Wheel delta
int32_t InputManager::GetMouseWheel() const 
{
	return nMouseWheelDelta;
}

// Get Mouse in window space
//const avl::Vector2f& InputManager::GetMousePosition(const ScreenRender& screen) const {}

// Get Mouse in desktop space
//const avl::Vector2f InputManager::GetMousePosition() const {}