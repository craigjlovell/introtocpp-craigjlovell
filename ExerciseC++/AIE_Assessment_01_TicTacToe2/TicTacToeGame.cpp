#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame()
{

}

TicTacToeGame::~TicTacToeGame()
{

}

int TicTacToeGame::DrawBoard(int x, int y)
{
	return board[x][y];
}

bool TicTacToeGame::SetBoard(int x, int y, int player)
{
	if (IsValidMove(x, y))
	{
		board[x][y] = player;
		return true;
	}

	return false;
}

bool TicTacToeGame::IsValidMove(int x, int y)
{
	return board[x][y] == 0;
}

char TicTacToeGame::DrawSquare(int x, int y, int location[2])
{
	char square = ' ';

	if (location[0] == x && location[1] == y)
	{
		return '+';
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

bool TicTacToeGame::CheckWinner(int player)
{

	for (int r = 0; r < 3; r++) //HOZ
	{
		int num = 0;
		for (int c = 0; c < 3; c++)
		{
			if (board[r][c] == player)
			{
				num++;
			}
			if (num == 3)
			{
				return true;
			}
		}
	}

	for (int r = 0; r < 3; r++) //VERT
	{
		int num = 0;
		for (int c = 0; c < 3; c++)
		{
			if (board[c][r] == player)
			{
				num++;
			}
			if (num == 3)
			{
				return true;
			}
		}
	}

	int num = 0;
	for (int rc = 0; rc < 3; rc++) //left to right
	{
		if (board[rc][rc] == player)
		{
			num++;
		}
		if (num == 3)
		{
			return true;
		}
	}

	num = 0;
	for (int rc = 0; rc < 3; rc++) // right to left
	{
		if (board[rc][2 - rc] == player)
		{
			num++;
		}
		if (num == 3)
		{
			return true;
		}
	}
	return false;
}
