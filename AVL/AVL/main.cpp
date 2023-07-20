#include <iostream>

#include "AVL.h"

class Example : public avl::AVL
{
};

void Events()
{
	std::cout << "Eu sou a função de chamada de eventos." << std::endl;
}

int main()
{
	Example demo;
	demo.Render(800, 800, avl::BLACK, []() { Events(); });

	std::cout << demo.GetSize();

	return 0;
}