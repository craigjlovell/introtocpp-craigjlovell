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
	PrintCommands();
	while (m_shouldExit == false)
	{
		InPutCommands(filename);
	}
	
	PrintPlayers();

	db.Save(filename);
}

void Application::PrintPlayers()
{
	for (int i = 0; i < db.Count(); i++)
	{
		Player* player = db.GetAt(i);
		std::cout << player->name << " : " << player->score << std::endl;
	}
}

void Application::StringToLower(std::string& lower)
{
	for (auto& c : lower)
	{
		c = tolower(c);
	}
}

void Application::PrintCommands()
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "           (Add Name Score)         " << std::endl;
	std::cout << "        Add a pleyer to records     " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "            (Remove Name)           " << std::endl;
	std::cout << "     Remove a pleyer from records   " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "               (Check)              " << std::endl;
	std::cout << "  Looks through records for a name  " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "               (Clear)              " << std::endl;
	std::cout << "   Clears all records and start new " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "               (Save)               " << std::endl;
	std::cout << "   Saves all newly added records    " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "               (Sort)               " << std::endl;
	std::cout << "  Sorts all records in a ABC order  " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "               (List)               " << std::endl;
	std::cout << "          List all records          " << std::endl;
	std::cout << "------------------------------------" << std::endl;
}

void Application::InPutCommands(const char* filename)
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "        Enter your command          " << std::endl;
	std::cout << "------------------------------------" << std::endl;

	std::string input;
	std::cin >> input;
	StringToLower(input);
	
	// todo convert input to lowercase

	if (input == "clear")
	{
		db.Clear();
		system("CLS");
	}

	if (input == "remove")
	{
		std::string removename;
		std::cout << "------------------------------------" << std::endl;
		std::cout << " Enter name to remove from reports: " << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cin >> removename;
		StringToLower(removename);

		bool removedSuccess = true;
		while (removedSuccess)
			removedSuccess = db.Remove(db.GetByName(removename.c_str()));

		system("CLS");
		PrintPlayers();
	}

	if (input == "check")
	{
		system("CLS");
		std::string findname;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "    Enter name to pull up record:   " << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cin >> findname;
		StringToLower(findname);

		Player* p = db.BinarySearch(findname.c_str());
		if (p != nullptr)
		{
			system("CLS");
			std::cout << p->name << " : " << p->score << " : Record Pulled" <<std::endl;
		}
		else
		{			
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
		system("CLS");
		int score = 0;
		std::string name;

		std::cout << "Enter a Name and then a Score: ";
		std::cin >> name >> score;
		StringToLower(name);

		Player* p = db.GetByName(name.c_str());
		if (p != nullptr)
		{
			std::cout << "name already in Record" << std::endl;
		}
		else
		{
			db.Add(name.c_str(), score);
			db.Sort();
			db.Save(filename);
		}
		PrintPlayers();
	}

	if (input == "list")
	{
		system("CLS");
		PrintPlayers();
	}

	if (input == "sort")
	{
		db.Sort();
		system("CLS");
		PrintPlayers();
	}

	if (input == "commands")
	{
		system("CLS");
		PrintCommands();
	}

	if (input == "update")
	{
		system("CLS");
		std::string update;
		PrintPlayers();
		std::cout << "Enter name of person you wish to edit: ";
		std::cin >> update;
		StringToLower(update);
	
		Player* p = db.GetByName(update.c_str());
		if (p != nullptr)
		{
			std::cout << p->name << " : " << p->score << std::endl;
		}
	
		int scoreEdit = 0;
		std::string nameEdit;
		std::cout << "Enter enter new name and score of record you would like to edit ";
		std::cin >> nameEdit >> scoreEdit;
		StringToLower(nameEdit);
		system("CLS");
	
		db.Remove(db.GetByName(update.c_str()));
		db.Add(nameEdit.c_str(), scoreEdit);
		db.Sort();
		db.Save(filename);
		PrintPlayers();
	}

	if (input == "exit")
	{
		system("CLS");
		m_shouldExit = true;
	}


	//else 
	//{
	//	system("CLS");
	//	std::cout << "------------------------------------" << std::endl;
	//	std::cout << "       Command Does not exist       " << std::endl;
	//	std::cout << "------------------------------------" << std::endl;
	//}

}