#include "InputManager.h"
#include "ScreenRender.h"

using namespace avl;

// Get State of key
SButton InputManager::GetKey(Key k) const 
{
	ValidateKey(k);
	return pKeyboardState[static_cast<int>(k)];
}

// Get State of mouse button
SButton InputManager::GetMouse(uint32_t b) const 
{
	ValidateMouseButton(b);
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
	ValidateMouseWheelDelta(event.mouseWheelScroll.delta);
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

// Validate the key value to ensure it's within a valid range
void InputManager::ValidateKey(Key k) const {
	if (!(static_cast<int>(k) >= 0 && static_cast<int>(k) < ENUM_END))
	{
		throw invalid_key();
	}
}

// Validate the mouse button index to ensure it's within a valid range
void InputManager::ValidateMouseButton(uint32_t b) const {
	if (!(b >= Mouse::LEFT && b <= Mouse::MIDDLE))
	{
		throw invalid_mouse_button();
	}
}

// Validate the mouse wheel delta to ensure it's within a reasonable range
void InputManager::ValidateMouseWheelDelta(int32_t delta) const {
	// You can define a valid range here, for example:
	if (!(delta >= -5 && delta <= 5))
	{
		throw invalid_mouse_delta();
	}
}