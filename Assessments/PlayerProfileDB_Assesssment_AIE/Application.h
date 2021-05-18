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

protected:

private:

	PlayerDB db;
};