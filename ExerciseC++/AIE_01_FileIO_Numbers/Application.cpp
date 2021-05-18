#include "Application.h"
#include <iostream>
#include <fstream>
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

	srand(time(0));//random number each time you run

	num1 = rand() % 1000;
	num2 = rand() % 1000;
	num3 = rand() % 1000;
	num4 = rand() % 1000;
	num5 = rand() % 1000;
	num6 = rand() % 1000;

	// save the above numbers to file
	SaveToFile(filename);

	// reset the numbers
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	num5 = 0;
	num6 = 0;

	LoadFromFile(filename);

	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;
	std::cout << num4 << std::endl;
	std::cout << num5 << std::endl;
	std::cout << num6 << std::endl;
}

void Application::SaveToFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios::out | std::ios::binary);
	file.write((char*)&num1, sizeof(num1));
	file.write((char*)&num2, sizeof(num2));
	file.write((char*)&num3, sizeof(num3));
	file.write((char*)&num4, sizeof(num4));
	file.write((char*)&num5, sizeof(num5));
	file.write((char*)&num6, sizeof(num6));
	file.close();

	return;

}

void Application::LoadFromFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios::in | std::ios::binary);
	file.read((char*)&num1, sizeof(num1));
	file.read((char*)&num2, sizeof(num2));
	file.read((char*)&num3, sizeof(num3));
	file.read((char*)&num4, sizeof(num4));
	file.read((char*)&num5, sizeof(num5));
	file.read((char*)&num6, sizeof(num6));
	file.close();

	return;
}

