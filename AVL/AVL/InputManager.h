#pragma once

#include <cstdint>

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Vector2D.h"
#include "ScreenRender.h"

namespace avl
{
	enum Key
	{
		NONE,
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		UP, DOWN, LEFT, RIGHT,
		SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
		BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
		NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
		MP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL, PERIOD,
		EQUALS, COMMA, MINUS,
		OEM_1, OEM_2, OEM_3, OEM_4, OEM_5, OEM_6, OEM_7, OEM_8,
		CAPS_LOCK, ENUM_END
	};

	namespace Mouse
	{
		static constexpr int32_t LEFT = 0;
		static constexpr int32_t RIGTH = 1;
		static constexpr int32_t MIDDLE = 2;
	};

	struct SButton
	{
		bool bPressed = false;
		bool bReleased = false;
		bool bHeld = false;
	};

	class InputManager
	{
	private:
		// State of keyboard		
		bool pKeyNewState[256] = { 0 };
		bool pKeyOldState[256] = { 0 };
		SButton	pKeyboardState[256] = { 0 };

		// State of mouse
		bool pMouseNewState[3] = { 0 };
		bool pMouseOldState[3] = { 0 };
		SButton	pMouseState[3] = { 0 };
		int32_t nMouseWheelDelta{ 0 };
	public:
		// Get State of key
		SButton GetKey(Key k) const;
		// Get State of mouse button
		SButton GetMouse(uint32_t b) const;
		// Get Mouse X coordinate
		int32_t GetMouseX() const;
		// Get Mouse Y coordinate
		int32_t GetMouseY() const;
		// Update Mouse Wheel Delta
		void UpdateMouseWheelDelta(const sf::Event& event);
		// Get Mouse Wheel delta
		int32_t GetMouseWheel() const;
		// Get Mouse in window space
		const avl::Vector2f& GetMousePosition(const ScreenRender& screen) const;
		// Get Mouse in desktop space
		const avl::Vector2f GetMousePosition() const;
	};
}
