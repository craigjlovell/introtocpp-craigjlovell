#include "TicTacToeGame.h"

int TicTacToeGame::DrawBoard(int x, int y)
{
	return board[x][y];
}

void TicTacToeGame::SetBoard(int x, int y, int player)
{
	board[x][y] = player;
}

char TicTacToeGame::DrawSquare(int x, int y, int location[2])
{
	char square = ' ';

	if (location[0] == x && location[1] == y)
	{
		return '#';
	}

	switch (board[x][y])
	{
	case 1:
		square = 'x';
		break;
	case 2:
		square = 'o';
		break;
	}
	return square;
}
