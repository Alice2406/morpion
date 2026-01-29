#pragma once
#include "Opponent.h"
#include <iostream>

struct Move
{
	unsigned int x;
	unsigned int y;
};

class IA : public Opponent
{
public:
	Gamestate Play(Gamestate state) override;
	Move FindBestMove(Gamestate state);
	int Minimax(Gamestate state, int gameTurn, bool isMax);
	int min(int a, int b);
	int max(int a, int b);
};

