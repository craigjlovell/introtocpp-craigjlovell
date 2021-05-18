#pragma once

#include <string>

class Dragon
{
public:

	std::string name;

	static const int DAYS_PER_WEEK = 7;
	int foodEatenPerDay[DAYS_PER_WEEK];

public:

	// default constructor
	Dragon();

	// overloaded constructor
	Dragon(const char* name);

	// destructor
	~Dragon();

	void Print();
};

