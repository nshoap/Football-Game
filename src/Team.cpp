#include "Team.h"

size_t Team::team_count = 0;

void Team::Setup()
{
	/* Check if team is already set-up */
	if (head_coach != nullptr || !roster.empty())
		throw std::string("Attempt to setup already initialized team!");

	name = "Team " + std::to_string(team_count);
	++team_count;
}

std::string Team::GetName()
{
	return name;
}

const std::vector<Player*> Team::GetRoster()
{
	return roster;
}

void Team::FillRoster(std::vector<Player*>& free_agents)
{
	Player* player = nullptr;
	bool offer_accepted = false;

	/* Attempt to keep signing free agents until the roster is filled or there are no free agents to sign */
	while (!free_agents.empty() && roster.size() < 53)
	{
		/* Grab player and offer player */
		/* TODO: Implement actual offer logic; for now, players will automatically accept offers */
		player = free_agents.back();
		offer_accepted = player->ViewOffer(100);
		if (offer_accepted)
		{
			player->Setup(this);
			roster.push_back(player);
			free_agents.pop_back();
		}
	}
}

void Team::HireCoach(Coach* coach)
{
	if (coach != nullptr)
	{
		head_coach = coach;
		coach->Setup(this);
	} else throw std::string("Invalid coach pointer passed to Team::HireCoach");
}
