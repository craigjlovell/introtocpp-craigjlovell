#include "Application.h"

#include <iostream>

Application::Application()
{

}

Application::~Application()
{

}

bool Application::CheckWinner(char board[3][3], char player)
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

void Application::Run()
{
	std::cout << "Hello World" << std::endl;

	std::cout << CheckWinner(board0, 'x') << std::endl;
	std::cout << CheckWinner(board0, 'o') << std::endl;
	std::cout << CheckWinner(board1, 'x') << std::endl;
	std::cout << CheckWinner(board1, 'o') << std::endl;
	std::cout << CheckWinner(board2, 'x') << std::endl;
	std::cout << CheckWinner(board2, 'o') << std::endl;
	std::cout << CheckWinner(board3, 'x') << std::endl;
	std::cout << CheckWinner(board3, 'o') << std::endl;
	std::cout << CheckWinner(board4, 'x') << std::endl;
	std::cout << CheckWinner(board4, 'o') << std::endl;
}


