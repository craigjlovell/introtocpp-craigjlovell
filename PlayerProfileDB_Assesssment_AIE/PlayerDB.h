#pragma once
#include "Application.h"
#include "Player.h"

class PlayerDB
{
public:

	PlayerDB();
	~PlayerDB();

	void Add(const char* name, int score);
	void Remove(Player);
	void DisplayAllPlayers();
	void Clear();
	Player* GetByName(const char* name);
	void GetByScore();
	void GetHighScore();
	void UpdatePlayer(Player);
	void Sort();
	void Count();
	void Save(const char* filename);
	void Load(const char* filename);

protected:

	Player* m_record = nullptr;
	int m_count = 0;

private:

};