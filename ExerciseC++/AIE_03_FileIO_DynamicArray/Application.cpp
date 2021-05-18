#include "Application.h"
#include <iostream>
#include<fstream>
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

	// how many numbers do we want to create?
	m_numbers_count = (rand() % 20) + 1;

	std::cout << m_numbers_count << std::endl;

	// create array of numbers dynamicly
	m_numbers = new int[m_numbers_count];

	// initialise array with random values
	for (int i = 0; i < m_numbers_count; i++)
		m_numbers[i] = rand() % 100;

	// save the above numbers to file
	SaveToFile(filename);

	// reset the numbers
	delete[] m_numbers;
	m_numbers = nullptr;

	LoadFromFile(filename);

	// print to console
	// Note: nothing will print because the numbers array doesn't exist
	// until the LoadFromFile method completes successfuly

	if (m_numbers != nullptr)
	{
		for (int i = 0; i < m_numbers_count; i++)
			std::cout << m_numbers[i] << std::endl;

		// delete the numbers, we are finished with them
		delete[] m_numbers;
	}
}

void Application::SaveToFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios_base::out | std::ios_base::binary);

	if (file.is_open())
	{
		file.write((char*)&m_numbers_count, sizeof(int));
		file.write((char*)m_numbers, sizeof(int) * m_numbers_count);
	}

	file.close();
}

void Application::LoadFromFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios::in | std::ios::binary);

	if (file.is_open())
	{
		file.read((char*)&m_numbers_count, sizeof(int));

		m_numbers = new int[m_numbers_count];

		file.read((char*)m_numbers, sizeof(int) * m_numbers_count);
	}

	file.close();
}

