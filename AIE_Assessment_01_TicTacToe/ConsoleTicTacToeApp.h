#pragma once
#include "TicTacToeGame.h"

class ConsoleTicTacToe
{
public:
	ConsoleTicTacToe();
	~ConsoleTicTacToe();

	void Run();

	void Load();
	void Unload();

	void Update(float dt);
	void Draw();

	char Menu();
	void DrawBoard();
	void PlayerMove();
	bool CheckWin(int board[3][3], int player);

protected:
private:

	TicTacToeGame* game = nullptr;

	int m_Location[2] = {0, 0};
	int m_player = 1;

};