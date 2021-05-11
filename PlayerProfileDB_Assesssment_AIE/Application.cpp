#include "Application.h"
#include "PlayerDB.h"
#include "Player.h"
#include <iostream>

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
	const char* filename = "database.dat";
	db.Load(filename);

	db.DisplayAllPlayers();


	std::cout << "Enter your command" << std::endl;
	std::string input;
	std::cin >> input;

	if (input == "clear")
		db.Clear();

	if (input == "save")
		db.Save(filename);

	if (input == "add")
	{
		int score;
		std::string name;

		std::cout << "Enter a name: ";
		std::cin >> name;
		std::cout << "Enter a score: ";
		std::cin >> score;

		db.Add(name.c_str(), score);
	}
	
	
	//Player* p0 = db.GetByName("Hello");
	//if (p0 != nullptr)
	//	std::cout << p0->name << "\t\t" << p0->score << std::endl;
	//
	//
	//Player* p1 = db.GetByName("World");
	//if (p1 != nullptr)
	//	std::cout << p1->name << "\t\t" << p1->score << std::endl;
	//

	db.DisplayAllPlayers(); 


	db.Save(filename); // Step 1
}

