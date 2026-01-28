#include <iostream>
#include "Gamestate.h"

int main()
{
	Gamestate state;

	try
	{
		state.GetToken(100);
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
