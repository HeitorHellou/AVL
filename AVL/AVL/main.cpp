#include <iostream>
#include "AVL.h"

class Example : public avl::AVL
{
	virtual void OnUserStart() 
	{

	}

	virtual void OnUserUpdate() 
	{
		Clear(avl::RED);
		DrawString(400, 400, "hello world", avl::ARIAL, avl::BLACK, 24);
	}
};

int main()
{
	Example demo;
	demo.Render(800, 800);
	demo.Start();

	std::cout << demo.GetSize();

	return 0;
}