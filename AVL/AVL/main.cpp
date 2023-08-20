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
		
		/*auto deltaTime = GetDeltaTimeAsSeconds();
		std::cout << deltaTime;
		std::cout << "\n";*/
	}
};

int main()
{
	Example demo;

	demo.SetFrameRate(60);
	demo.Render(800, 800);
	demo.Start(false);

	std::cout << demo.GetSize();

	return 0;
}