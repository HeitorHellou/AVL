#pragma once

#include <iostream>
#include <exception>

// Error when the window reference is null
class target_renderWindow_error : public std::exception {
public:
    const char* what() const throw() {
        return "Target Render Window Error. Are you missing Render Window reference?";
    }
};

// Error when the position (x,y) is negative
class invalid_position : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid position set. Position must be a positive value.";
    }
};

// Error when the width or height are negative values
class invalid_width_height : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid width or height set. Width and Height value must be positive.";
    }
};

// Error when the radius is a negative value
class invalid_radius : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid radius value. Radius value must be positive.";
    }
};

// Error when the scale is an invalid value
class invalid_scale : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid scale value. The scale value must be positive, greater than zero and less than 50.";
    }
};

// Error when an invalid key is pressed
class invalid_key : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid key pressed. The key must be greater than zero, and less than 97.";
    }
};

// Error when an invalid mouse button is pressed
class invalid_mouse_button : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid mouse button pressed. The mouse button must be greater than zero, and less than 2.";
    }
};

// Error when an invalid wheel delta value is received
class invalid_mouse_delta : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid wheel delta value. The wheel delta was not in the value.";
    }
};

// Error when the framerate is a negative value
class invalid_frame_rate : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid framerate value. The framerate value must be greater than zero.";
    }
};