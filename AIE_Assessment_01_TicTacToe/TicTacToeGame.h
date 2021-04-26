#pragma once


class TicTacToeGame
{
public:
	int DrawBoard(int x, int y);
	void SetBoard(int x, int y, int player);
	char DrawSquare(int x, int y, int location[2]);
	

protected:
private:
	int board[3][3] = { // x = 1 o = 2
		{0, 0, 0}, 
		{0, 0, 0},  
		{0, 0, 0}};

};