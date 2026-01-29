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

	std::optional<Token> hasWinner;
	//ligne
	hasWinner = CheckWinRow(0, 1, 2);
	if (hasWinner)
		return hasWinner;
	hasWinner = CheckWinRow(3, 4, 5);
	if (hasWinner)
		return hasWinner;
	hasWinner = CheckWinRow(6, 7, 8);
	if (hasWinner)
		return hasWinner;
	//colomne
	hasWinner = CheckWinRow(0, 3, 6);
	if (hasWinner)
		return hasWinner;
	hasWinner = CheckWinRow(1, 4, 7);
	if (hasWinner)
		return hasWinner;
	hasWinner = CheckWinRow(2, 5, 8);
	if (hasWinner)
		return hasWinner;
	//diagonale
	hasWinner = CheckWinRow(0, 4, 8);
	if (hasWinner)
		return hasWinner;
	hasWinner = CheckWinRow(2, 4, 6);
	if (hasWinner)
		return hasWinner;

	return std::optional<Token>();
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

bool Gamestate::isFull()
{
	for (Token value : tokens)
		if (value == Token::EMPTY)
			return false;
	return true;
}

std::string Gamestate::ToString()
{
	std::string result;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			result += static_cast<char>(GetToken(x, y));
		}
		result += '\n';
	}
	return result;
}
