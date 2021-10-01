#include "Game.h"

void Game::Run()
{
	std::ifstream fin;
	std::string input;
	size_t index;

	fin.open("txt/welcome.txt");
	HesitateText(fin, std::cout, 10);
	fin.close();

	InitTeams();

	do
	{
		std::cout << '>' << std::flush;
		if (input == "?")
		{
			printf("? - Help\nP - Print Standings\nQ - Quit\n");
		}
		else if (input == "P")
		{
			printf("No standings to print.\n");
		}
		else if (input == "COACHES")
		{
			for (const auto& c : coach_database)
			{
				printf("%s coaches for %s\n", c->GetName().c_str(), c->GetTeam()->GetName().c_str());
			}
		}
		else if (input == "PLAYERS")
		{
			for (const auto& p : player_database)
			{
				printf("%s plays for %s\n", p->GetName().c_str(), p->GetTeam()->GetName().c_str());
			}
		}
		else if (input == "GET_TEAM")
		{
			std::cin >> input;
			try {
				index = std::stoul(input);
				if (index < teams.size())
				{
					auto roster = teams[index]->GetRoster();
					printf("%s\n", teams[index]->GetName().c_str());
					for (const auto& t : roster)
					{
						printf("%s\n", t->GetName().c_str());
					}
					
				}
			} catch (...) {
				printf("ERROR: Could not parse input into integer\n");
			}
			
		}
		else if (input == "Q")
		{
			Shutdown();
			return;
		}
	} while (std::getline(std::cin, input));
}

void Game::InitTeams()
{
	Team* t = nullptr;
	/* Check if not empty; throw error if teams already exist */
	if (!teams.empty()) throw std::string("Attempt to re-initialize teams!");
	
	/* Create a new team until we reach the number of teams */
	while (teams.size() != MAX_TEAM_COUNT)
	{
		t = new Team;
		t->Setup();
		teams.push_back(t);
	}
}

void Game::Shutdown()
{
	std::ifstream fin;
	fin.open("txt/goodbye.txt");
	HesitateText(fin);
	return;
}
