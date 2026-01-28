#include "Gamestate.h"

Token Gamestate::GetToken(unsigned int x, unsigned int y)
{
	return GetToken(y * 3 + x);
}

Token Gamestate::GetToken(unsigned int id) {
	if (id >= 9 || id < 0)
		throw std::out_of_range("Index out of range");
	return tokens[id];
}

bool Gamestate::SetToken(unsigned int x, unsigned int y, Token token)
{
	return SetToken(y * 3 + x, token);
}

bool Gamestate::SetToken(unsigned int id, Token token)
{
	if (id >= 9 || id < 0)
		throw std::out_of_range("Index out of range");
	if (GetToken(id) != Token::EMPTY)
		return false;
	tokens[id] = token;
	return true;
}

std::optional <Token> Gamestate::CheckWin()
{
	CheckWinRow(0, 1, 2);
	CheckWinRow(3, 4, 5);
	CheckWinRow(6, 7, 8);
}

std::optional <Token> Gamestate::CheckWinRow(unsigned int a, unsigned int b, unsigned c)
{
	if (tokens[a] == tokens[b] && tokens[b] == tokens[c])
	{
		if (tokens[a] == Token::EMPTY)
			return std::optional<Token>();
		return std::optional <Token> (tokens[a]);
	}
	return std::optional<Token>();
}
