#pragma once
#include "TicTacToeGame.h"

enum class GameState
{
	MENU,
	GAME,
	WIN
};

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

	void RunMenuState();
	void RunGameState();
	void RunWinState();

	void Borader();
	int GetPressedKey();
	int MovePlayer();
	char GetBoardCharacter(int row, int col, int location[2]);

	void PlacePlayer();
	void DrawBoard();

protected:

	bool m_ShouldQuit = false;
	GameState m_GameState = GameState::MENU;

private:

	TicTacToeGame* game = nullptr;

	int m_Location[2] = { 0, 0 };
	int m_player = 1;

};