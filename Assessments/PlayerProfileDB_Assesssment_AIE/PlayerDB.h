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
	
	void Clear();
	Player* GetAt(int index);
	Player* GetByName(const char* name);
	Player* BinarySearch(const char* name);
	void Sort();
	int Count();
	void Save(const char* filename);
	void Load(const char* filename);

protected:

	Player* m_record = nullptr;
	int m_count = 0;

private:

};