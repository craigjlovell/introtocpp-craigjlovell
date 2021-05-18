#pragma once
#include <iostream>

class Application
{
public:

	Application();
	~Application();

	bool CheckWinner(char board[3][3], char player);
	void Run();

protected:
private:

	char board0[3][3] =
	{
		{'x', ' ', ' '},
		{' ', 'x', ' '},
		{' ', ' ', 'x'}
	};

	char board1[3][3] =
	{
		{' ', 'o', ' '},
		{' ', 'o', ' '},
		{' ', 'o', ' '}
	};

	char board2[3][3] =
	{
		{' ', 'o', ' '},
		{'x', 'x', 'x'},
		{' ', 'o', ' '}
	};

	char board3[3][3] =
	{
		{'x', 'o', 'o'},
		{'x', 'o', 'x'},
		{'o', 'x', 'x'}
	};
	char board4[3][3] =
	{
		{'o', 'o', 'x'},
		{'x', 'x', 'o'},
		{'o', 'x', 'x'}
	};

};

