#include <iostream>
#include "AVL.h"

class Example : public avl::AVL
{
	virtual void OnUserStart() 
	{
		
	}

	virtual void OnUserUpdate() 
	{
		
	}
};

int main()
{
	Example demo;
	demo.Render(800, 800, avl::RED);
	demo.Start();

	std::cout << demo.GetSize();

	return 0;
}