#include <iostream>
#include <string>
#include <cstring>
#include "PersonGreeting.h"
// Next Refactor

// Great work


int GreetPerson(std::string name)
{

	std::cout << "Hello " << name << "\n";

	std::cout << NameLength(name) << std::endl;

	std::cout << NumberOfVowels(name) << std::endl;

	std::cout << Upper(name) << std::endl;

	std::cout << Lower(name) << std::endl;

	std::cout << FristLastName(name) << std::endl;

	std::cout << Rev(name) << std::endl;

	return 0;
}

int main(int argc, char** argv)
{
	std::string names[12] = { "Craig Lovell", "John Schepis", "Jordan Wesson", "Sam Yorng", "Daniel Mayo", "Steven Castano", "Jack Norrie", "Bailey Kan", "Flynn May", "Ben Scott", "Jordan Cox", "Omar Samad" };

	for (int i = 0; i < 12; i++)
	{
		GreetPerson(names[i]);
		std::cout << "\n";
	}

	return 0;
}