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

