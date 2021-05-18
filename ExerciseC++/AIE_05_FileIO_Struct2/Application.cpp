#include "Application.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
	const char* filename = "data.dat";

	srand(time(0));

	m_dragons[0] = Dragon("fluffy");
	m_dragons[1] = Dragon("bunny");
	m_dragons[2] = Dragon("kittens");
	m_dragons[3] = Dragon("spike");
	m_dragons[4] = Dragon("bob");

	// save the above numbers to file
	SaveToFile(filename);

	m_dragons[0] = Dragon();
	m_dragons[1] = Dragon();
	m_dragons[2] = Dragon();
	m_dragons[3] = Dragon();
	m_dragons[4] = Dragon();

	LoadFromFile(filename);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		m_dragons[i].Print();
	}

}

void Application::SaveToFile(const char* filename)
{
	std::fstream file;
	file.open(filename);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		// save each dragon individually
		SaveDragon(file, &m_dragons[i]);
	}

	file.close();
}

void Application::LoadFromFile(const char* filename)
{
	// TODO: write your code here
	// See how we've structured the SaveToFile method
	// this should look simular

	std::fstream file;
	file.open(filename);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		LoadDragon(file, &m_dragons[i]);
	}

	file.close();
}

void Application::SaveDragon(std::fstream& file, const Dragon* dragon)
{
	// TODO: write code to write the dragons data to file
	// remember, this time the dragons name is an std::string
	// so you'll need to read/write its data seperatelly as the name
	// is a variable length.

	int name_length = dragon->name.length();

	file.write((char*)&name_length, sizeof(int));

	for (int i = 0; i < name_length; i++)
	{
		file.write((char*)&dragon->name[i], sizeof(char));
	}

	file.write((char*)&dragon->foodEatenPerDay[0], sizeof(int) * 7);
}

void Application::LoadDragon(std::fstream& file, Dragon* dragon)
{

	// TODO: write code to read the dragons data from file
	// remember, this time the dragons name is an std::string
	// so you'll need to read/write its data seperatelly as the name
	// is a variable length.
	int name_length = 0;

	file.read((char*)&name_length, sizeof(int));

	for (int i = 0; i < name_length; i++)
	{
		char c;
		file.read((char*)&c, sizeof(char));

		dragon->name += c;
	}

	file.read((char*)&dragon->foodEatenPerDay[0], sizeof(int) * 7);
}