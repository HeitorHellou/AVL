#include <iostream>

#include "AVL.h"

class Example : public avl::AVL
{

};

int main()
{
	Example demo;
	demo.Render(800, 800, avl::BLACK);

	std::cout << demo.GetSize();

	return 0;
}