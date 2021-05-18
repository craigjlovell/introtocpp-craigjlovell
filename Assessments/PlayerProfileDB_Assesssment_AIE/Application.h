#pragma once
#pragma once
#include "PlayerDB.h"
#include "Player.h"
#include <string>

class Application
{
public:



	Application();
	~Application();

	void Run();

	void PrintPlayers();
	void PrintCommands();
	void InPutCommands(const char* filename);

protected:

private:

	PlayerDB db;
	bool m_shouldExit = false;
};