#include <iostream>
#include "AVL.h"

class Example : public avl::AVL
{
	virtual void OnUserStart() 
	{
		
	}

	virtual void OnUserUpdate() 
	{
		Draw(300, 100, 400, 400);
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