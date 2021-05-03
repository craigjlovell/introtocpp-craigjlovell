#pragma once
#include <iostream>

class Application
{
public:

	std::string dragons[3];
	std::string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	int food[3][7];
	int avg[3];

	Application();
	~Application();

	void FoodData();
	void EnterDragonNames();
	void MinMax();
	void Run();

protected:
private:
};

