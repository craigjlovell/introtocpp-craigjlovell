#pragma once
#pragma once
#include "Application.h"
#include "PlayerDB.h"

class Player
{

public:

	char name[32];
	int score;

public:

	Player();
	~Player();
	Player(const char* name, int score);

protected:

private:


};