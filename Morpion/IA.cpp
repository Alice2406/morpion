#include "IA.h"

int IA::min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int IA::max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int IA::Minimax(Gamestate state, int gameTurn, bool isMax)
{
	std::optional <Token> win = state.CheckWin();

	if (win == Token::O)
		return (gameTurn - 100);
	else if (win == Token::X)
		return (100 - gameTurn);

	if (state.isFull())
		return 0;
	if (isMax)
	{
		int best = -1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (state.GetToken(i, j) == Token::EMPTY)
				{
					state.SetToken(i, j, Token::X);
					best = max(best, Minimax(state, gameTurn + 1, !isMax));
					state.SetToken(i, j, Token::EMPTY);
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (state.GetToken(i, j) == Token::EMPTY)
				{
					state.SetToken(i, j, Token::O);
					best = min(best, Minimax(state, gameTurn + 1, !isMax));
					state.SetToken(i, j, Token::EMPTY);
				}
			}
		}
		return best;
	}
}

Move IA::FindBestMove(Gamestate state)
{
	Move BestMove;
	int BestVal = -1000;
	BestMove.x = -1;
	BestMove.y = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (state.GetToken(i, j) == Token::EMPTY)
			{
				state.SetToken(i, j, Token::X);
				int move = Minimax(state, 0, false);
				state.SetToken(i, j, Token::EMPTY);
				if (move > BestVal)
				{
					BestMove.x = i;
					BestMove.y = j;
					BestVal = move;
				}
			}
		}
	}
    return BestMove;
}


Gamestate IA::Play(Gamestate state){
	Move BestMove;

	BestMove = FindBestMove(state);
	state.SetToken(BestMove.x, BestMove.y, Token::X);
	return (state);
}