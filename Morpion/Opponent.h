#pragma once
#include "Gamestate.h"

class Opponent
{
public: 
	virtual Gamestate Play(Gamestate state) = 0;
};

