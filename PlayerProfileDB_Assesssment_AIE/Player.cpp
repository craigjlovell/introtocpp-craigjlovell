#include "Application.h"
#include "PlayerDB.h"
#include "Player.h"
#include <cstring>
#include <iostream>

Player::Player()
{
	strcpy_s(name, "");
	score = 0;
}

Player::~Player()
{

}

Player::Player(const char* name, int score)
{
	strcpy_s(this->name, name);
	this->score = score;
}