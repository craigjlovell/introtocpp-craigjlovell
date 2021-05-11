#include "Application.h"
#include "PlayerDB.h"
#include "Player.h"
#include <iostream>
#include <cstring>
#include<fstream>

PlayerDB::PlayerDB()
{

}

PlayerDB::~PlayerDB()
{

}

//void PlayerDB::Add(char name[32], int score)
void PlayerDB::Add(const char* name, int score)
{
	Player player(name, score);
	Player* temp = new Player[m_count + 1];

	for (int i = 0; i < m_count; i++)
	{
		temp[i] = m_record[i];
	}

	temp[m_count] = player;
	m_count += 1;

	delete[] m_record;
	m_record = temp;
}

void PlayerDB::DisplayAllPlayers()
{
	for (int i = 0; i < m_count; i++)
	{
		std::cout << m_record[i].name << ": " << m_record[i].score << std::endl;
	}
}

void PlayerDB::Remove(Player)
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_record[i] == Player().name[32])
		{

		}
	}
}

void PlayerDB::Clear()
{
	delete[] m_record;
	m_record = nullptr;
	m_count = 0;
}

Player* PlayerDB::GetByName(const char* name)
{
	for (int i = 0; i < m_count; i++)
	{
		//if(m_record[i].name == name)
		if (strcmp(m_record[i].name, name) == 0)
		{
			return &m_record[i];
		}
	}
	return nullptr;
}

void PlayerDB::GetByScore()
{

}

void PlayerDB::GetHighScore()
{

}

void PlayerDB::UpdatePlayer(Player)
{

}

void PlayerDB::Sort()
{

}

void PlayerDB::Count()
{

}

void PlayerDB::Save(const char* filename)
{
	std::fstream file;
	file.open(filename, std::ios_base::out | std::ios_base::binary);

	if (file.is_open())
	{
		file.write((char*)&m_count, sizeof(int));
		file.write((char*)m_record, sizeof(Player) * m_count);
	}
	file.close();
}

void PlayerDB::Load(const char* filename)
{
	std::fstream file;
	file.open(filename, std::ios_base::in | std::ios_base::binary);

	if (file.is_open())
	{
		file.read((char*)&m_count, sizeof(int));
		m_record = new Player[m_count];
		file.read((char*)m_record, sizeof(Player) * m_count);
	}
	file.close();
}
