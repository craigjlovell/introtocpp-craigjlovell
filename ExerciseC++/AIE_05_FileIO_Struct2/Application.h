#pragma once

#include "Dragon.h"
#include <fstream>

class Application
{
public:

	Application();
	~Application();

	void Run();

	void SaveToFile(const char* filename);
	void LoadFromFile(const char* filename);

	void SaveDragon(std::fstream& file, const Dragon* dragon);
	void LoadDragon(std::fstream& file, Dragon* dragon);

protected:

	static const int NUM_DRAGONS = 5;
	Dragon m_dragons[NUM_DRAGONS];

private:

};
