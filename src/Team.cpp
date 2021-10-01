#include "Team.h"

size_t Team::team_count = 0;

void Team::Setup()
{
	Player* player = nullptr;

	/* Check if team is already set-up */
	if (head_coach != nullptr || !roster.empty())
		throw std::string("Attempt to setup already initialized team!");

	name = "Team " + std::to_string(team_count);
	++team_count;

	head_coach = new Coach;
	head_coach->Setup(this);

	while (roster.size() != MAX_ROSTER_SIZE)
	{
		player = new Player;
		player->Setup(this);
		roster.push_back(player);
	}
}

std::string Team::GetName()
{
	return name;
}

const std::vector<Player*> Team::GetRoster()
{
	return roster;
}

