#pragma once
#include "Application.h"
#include "Player.h"

class PlayerDB
{
public:

	PlayerDB();
	~PlayerDB();

	void Add(const char* name, int score);
	bool Remove(Player* player);
	void DisplayAllPlayers();
	void Clear();
	Player* GetByName(const char* name);
	void GetByScore();
	Player* BinarySearch(const char* name);
	void UpdatePlayer(Player);
	void Sort(const char* name);
	void Count();
	void Save(const char* filename);
	void Load(const char* filename);

protected:

	Player* m_record = nullptr;
	int m_count = 0;

private:

};