#include "TicTacToeGame.h"
#include <raylib.h>

TicTacToeGame::TicTacToeGame()
{

}

TicTacToeGame::~TicTacToeGame()
{

}

int TicTacToeGame::DrawBoard(int x, int y)
{
	return m_board[x][y];
}

bool TicTacToeGame::SetBoard(int x, int y, int player)
{
	if (IsValidMove(x, y))
	{
		m_board[x][y] = player;
		return true;
	}

	return false;
}

bool TicTacToeGame::IsValidMove(int x, int y)
{
	return m_board[x][y] == 0;
}

char TicTacToeGame::DrawPlayer(int row, int col, int location[2])
{
	char square = ' ';

	if (location[0] == row && location[1] == col && m_board[row][col] == 0)
		return '#';


	switch (m_board[row][col])
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

void TicTacToeGame::Reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_board[i][j] = 0;
		}
	}
}

bool TicTacToeGame::CheckWinner(int player)
{

	for (int r = 0; r < 3; r++) //HOZ
	{
		int num = 0;
		for (int c = 0; c < 3; c++)
		{
			if (m_board[r][c] == player)
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
			if (m_board[c][r] == player)
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
		if (m_board[rc][rc] == player)
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
		if (m_board[rc][2 - rc] == player)
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

