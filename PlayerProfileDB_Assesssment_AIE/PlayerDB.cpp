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

bool PlayerDB::Remove(Player* player)
{
	if (player == nullptr)
		return false;

	bool removedPlayer = false;

	Player* temp = new Player[m_count];

	int count = 0;

	for (int i = 0; i < m_count; i++)
	{
		if (player != &m_record[i])
		{
			temp[count] = m_record[i];
			count += 1;
		}
		else
		{
			removedPlayer = true;
		}
	}

	m_count -= 1;
	delete[] m_record;
	m_record = temp;

	return removedPlayer;
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

Player* PlayerDB::BinarySearch(const char* name)
{
	// TODO: write your code here
	int left = 0;
	int right = m_count - 1;
	int middle = 0;


	while (left <= right)
	{
		middle = floor(((left + right) / 2));

		int cmpResult = strcmp(m_record[middle].name, name);


		if (cmpResult == 0)
		{
			return &m_record[middle];
		}
		else if (cmpResult > 0)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return nullptr;
}

void PlayerDB::GetByScore()
{

}

void PlayerDB::UpdatePlayer(Player)
{

}

void PlayerDB::Sort(const char* name)
{
	int result;
	for (int names = 0; names < m_count - 1; ++names)
	{
		for (int j = 0; j < m_count - 1 - names; ++j)
		{            
			result = strcmp(m_record[j].name, m_record[j + 1].name);              
			if (result > 0)
			{
				std::swap(m_record[j].name, m_record[j + 1].name);
			}
		}	 	
	}
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
