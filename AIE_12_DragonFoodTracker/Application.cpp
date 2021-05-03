#include "Application.h"
#include <math.h>
#include <iostream>
#include <string>

Application::Application()
{

}

Application::~Application()
{

}

void Application::FoodData()
{
	srand(time(NULL));

	avg[0] = 0;
	avg[1] = 0;
	avg[2] = 0;

	for (int d = 0; d < 3; d++)
	{
		for (int y = 0; y < 7; y++)
		{
			food[d][y] = rand() % 90 + 10;
			avg[d] += food[d][y];
		}
	}
}
void Application::EnterDragonNames()
{
	std::cout << "Enter First Dragons Name" << std::endl;
	std::cin >> dragons[0];

	std::cout << "Enter Second Dragons Name" << std::endl;
	std::cin >> dragons[1];

	std::cout << "Enter Third Dragons Name" << std::endl;
	std::cin >> dragons[2];

	system("clear");
}

void Application::MinMax()
{
	int min = 1;
	int max = 0;
	int minDragon = 0;
	int maxDragon = 0;
	int minDay = 0;
	int maxDay = 0;

	std::cout << days[0] << " " << days[1] << " " << days[2] << " " << days[3] << " " << days[4] << " " << days[5] << " " << days[6] << " " << days[6] << " " << "Average" << std::endl;

	for (int d = 0; d < 3; d++)
	{
		std::cout << dragons[d] << " ";
		for (int y = 0; y < 7; y++)
		{
			if (food[d][y] > max)
			{
				max = food[d][y];
				maxDay = y;
				maxDragon = d;
			}
			if (food[d][y] < min)
			{
				min = food[d][y];
				minDay = y;
				minDragon = d;
			}
			std::cout << food[d][y] << " ";
		}
		std::cout << " " << avg[d] / 7;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Max: " << dragons[maxDragon] << " Had " << food[maxDragon][maxDay] << "Kg of food on " << days[maxDay] << std::endl;
	std::cout << "Min: " << dragons[maxDragon] << " Had " << food[maxDragon][minDay] << "Kg of food on " << days[minDay] << std::endl;
}

void Application::Run()
{
	EnterDragonNames();
	FoodData();
	MinMax();
}