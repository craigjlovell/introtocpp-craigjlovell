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
	bool command = true;
	while (command)
	{
		std::cout << "Enter your command" << std::endl;
		std::string input;
		std::cin >> input;

		if (input == "clear")
		{
			db.Clear();
			system("CLS");
		}

		if (input == "remove")
		{
			std::string removename;
			std::cout << "Enter name to remove from reports: ";
			std::cin >> removename;

			bool removedSuccess = true;
			while (removedSuccess)
				removedSuccess = db.Remove(db.GetByName(removename.c_str()));

			system("CLS");
			db.DisplayAllPlayers();
		}

		if (input == "check")
		{			

			system("CLS");
			std::string findname;
			std::cout << "Enter name to pull up info: ";
			std::cin >> findname;

			Player* p = db.BinarySearch(findname.c_str());
			if (p != nullptr)
			{
				std::cout << p->name << ":" << p->score << std::endl;
			}
			else
			{
				system("CLS");
				std::cout << "No info was found under " << findname.c_str() << std::endl;
			}
		}

		if (input == "save")
		{
			db.Save(filename);
			system("CLS");
		}

		if (input == "add")
		{
			int score;
			std::string name;

			std::cout << "Enter a name: ";
			std::cin >> name;
			std::cout << "Enter a score: ";
			std::cin >> score;
			//db.Add(name.c_str(), score);

			Player* p = db.BinarySearch(name.c_str());
			if(p != nullptr)
			{
				system("CLS");
				std::cout << "name already in Record" << std::endl;
			
				std::cout << "name fsogfhwiguhewiogewognwe in Record" << std::endl;
			}
			else
			{				
				db.Add(name.c_str(), score);
			}

			db.DisplayAllPlayers();
		}

		if (input == "list")
		{
			system("CLS");
			db.DisplayAllPlayers();
		}

		if (input == "sort")
		{
			db.Sort(Player().name);
			system("CLS");
			db.DisplayAllPlayers();
		}

		if (input == "exit")
		{
			command = false;
		}
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

