#pragma once
#include "Opponent.h"
#include <iostream>
#include "Gamestate.h"
class Player : public Opponent
{
public:
	Gamestate Play(Gamestate state) override {
		unsigned int x;
		unsigned int y;

		std::cout << "quelle case vous voulez jouer ?" << std::endl;
		std::cin >> y;
		std::cin >> x;
		state.SetToken(x, y, Token::O);
		return (state);
	}

};

