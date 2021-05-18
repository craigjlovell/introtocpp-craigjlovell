#include <iostream>
#include <string>
#include <cstring>
#include "PersonGreeting.h"

std::string NameLength(const std::string name)
{
	std::string namelength = "";

	int space = 0;

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == ' ') space++;
	}

	std::cout << name << " Names Length is " << name.length() - space;

	return namelength;
}

std::string NumberOfVowels(const std::string name)
{
	std::string vowels = "";

	int vowel = 0;
	int index = 0;

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
		{
			index++;
		}
	}

	vowel++;

	std::cout << "You have this many vowels in your name " << index;

	return vowels;
}

std::string Upper(const std::string name)
{
	std::string upper = "";

	for (int i = 0; i < name.length(); i++)
	{
		putchar(toupper(name[i]));
	}

	return upper;
}

std::string Lower(const std::string name)
{
	std::string lower = "";

	for (int i = 0; i < name.length(); i++)
	{
		putchar(tolower(name[i]));
	}

	return lower;
}

std::string FristLastName(const std::string& name)
{
	std::string sepNames = "";

	std::cout << "Firstname: ";

	int index = 0;

	while (true)
	{
		if (name[index] == '\0')
		{
			break;
		}
		if (name[index] == ' ')
		{
			std::cout << std::endl;
			std::cout << "Lastname: ";
		}
		else
		{
			std::cout << name[index];
		}

		index++;
	}

	return sepNames;
}

std::string Rev(const std::string& name)
{

	std::string reversed = "";

	int index = name.length();

	for (int i = 0; i < name.length() + 1; i++)
	{
		if (index < 0)
		{
			break;
		}

		reversed += name[index];
		index--;
	}

	return reversed;
}