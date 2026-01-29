#include <iostream>
#include "Gamestate.h"
#include "Opponent.h"
#include "Player.h"
#include "IA.h"

using namespace std;
int main()
{
	Gamestate state;

	Opponent *opponent = new Player;
	Opponent *opponent2 = new IA;

	while (!state.isFull())
	{
		state = opponent->Play(state);
		cout << state.ToString() << endl;
		if (state.CheckWin())
			break;
		state = opponent2->Play(state);
		cout << state.ToString() << endl;
		if (state.CheckWin())
			break;
	}


	return 0;
}
