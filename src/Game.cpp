#include "Game.h"

void Game::Run()
{
	std::ifstream fin;
	std::string input;
	size_t index;

	fin.open("txt/welcome.txt");
	HesitateText(fin, std::cout, 10);
	fin.close();

	Init();

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
			for (const auto& c : coaches)
			{
				try {
					printf("%s coaches for %s\n", c->GetName().c_str(), c->GetTeam()->GetName().c_str());
				} catch (const std::string& e) {
					printf("%s is unemployed.\n", c->GetName().c_str());
				}
			}
		}
		else if (input == "PLAYERS")
		{
			for (const auto& p : players)
			{
				try {
					printf("%s plays for %s\n", p->GetName().c_str(), p->GetTeam()->GetName().c_str());
				} catch (const std::string& e)
				{
					printf("%s is unemployed.\n", p->GetName().c_str());
				}
			}
		}
		else if (input == "GET_TEAM")
		{
			std::cin >> input;
			try {
				index = std::stoul(input);
				if (index < teams.size())
				{
					const auto& roster = teams[index]->GetRoster();
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

void Game::Init()
{
	/* Check if not empty; throw error if teams already exist */
	if (!teams.empty()) throw std::string("Attempt to re-initialize teams!");

	/* Create players; create extra so free agents exist */
	while (players.size() != (MAX_TEAM_COUNT * MAX_ROSTER_SIZE * 1.5))
	{
		CreatePlayer();
	}

	/* Create a new team until we reach the number of teams */
	while (teams.size() != MAX_TEAM_COUNT)
	{
		Team* team = CreateTeam();
		Coach* coach = CreateCoach();
	
		team->HireCoach(coach);

		team->FillRoster(free_agents);
	}
}

/* TODO:
 * Decide how to handle this.
 * I think it makes sense that the *game* is supposed to create the teams, players, and coaches separately.
 * Teams should not create coaches or players because they are separate entities.
 * Teams are composed of coaches and players, but also have different attributes.
 * Players and Coaches are persons, individuals that exist indep. from the team.
 * Firstly, we need to implement some sort of save file loading.  That will come later.
 * For now, we want to generate players and coaches; store their memory address in a vector that stores the global database.
 * Secondly, we want to generate the amount of teams.  The amount of players and coaches will depend on MAX_TEAMS and will be MAX_TEAMS * MAX_ROSTER plus several hundred more for free agents.
 * I believe I will setup a draft type situation, teams will select coaches and players from the available pool.
 */

Team* Game::CreateTeam()
{
	Team* team = new Team;
	team->Setup();
	teams.push_back(team);
	return team;
}

Player* Game::CreatePlayer()
{
	Player* player = new Player;
	players.push_back(player);
	free_agents.push_back(player);
	return player;
}

Coach* Game::CreateCoach()
{
	Coach* coach = new Coach;
	coaches.push_back(coach);
	return coach;
}

void Game::Shutdown()
{
	std::ifstream fin;
	fin.open("txt/goodbye.txt");
	HesitateText(fin);
	return;
}
