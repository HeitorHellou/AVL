#include "InputManager.h"

using namespace avl;

// Get State of key
SButton InputManager::GetKey(Key k) const {}
// Get State of mouse button
SButton InputManager::GetMouse(uint32_t b) const {}
// Get Mouse X coordinate
int32_t InputManager::GetMouseX() const {}
// Get Mouse Y coordinate
int32_t InputManager::GetMouseY() const {}
// Get Mouse Wheel delta
int32_t InputManager::GetMouseWheel() const {}
// Get Mouse in window space
const avl::Vector2f& InputManager::GetMousePosition(const ScreenRender& screen) const {}
// Get Mouse in desktop space
const avl::Vector2f InputManager::GetMousePosition() const {}