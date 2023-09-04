#pragma once

#include <iostream>
#include <exception>

class target_renderWindow_error : public std::exception {
public:
    const char* what() const throw() {
        return "Target Render Window Error. Are you missing Render Window reference?";
    }
};

class invalid_position : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid position set. Position must be a positive value.";
    }
};

class invalid_width_height : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid width or height set. Width and Height value must be positive.";
    }
};

class invalid_radius : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid radius value. Radius value must be positive.";
    }
};

class invalid_scale : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid scale value. The scale value must be positive, greater than zero and less than 50.";
    }
};