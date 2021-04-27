#pragma once


class TicTacToeGame
{
public:

	TicTacToeGame();
	~TicTacToeGame();


	int DrawBoard(int x, int y);
	bool SetBoard(int x, int y, int player);
	char DrawPlayer(int row, int col, int location[2]);
	bool IsValidMove(int x, int y);
	bool CheckWinner(int player);

protected:
private:
	int board[3][3] = { // x = 1 o = 2
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0} };

};