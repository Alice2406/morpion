#pragma once
#include <stdexcept>
#include <vector>
#include <optional>

enum class Token : char {
	EMPTY = ' ',
	X = 'X',
	O = 'O'
};

class Gamestate
{
	std::vector<Token> tokens;
public :
	Gamestate() : tokens (9, Token::EMPTY) { }
	Token GetToken(unsigned int x, unsigned int y);
	Token GetToken(unsigned int id);
	bool SetToken(unsigned int x, unsigned int y, Token token);
	bool SetToken(unsigned int id, Token token);

	std::optional <Token> CheckWin();
	std::optional <Token> CheckWinRow(unsigned int a, unsigned int b, unsigned c);
};

