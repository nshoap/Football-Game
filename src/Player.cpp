#include "Player.h"

size_t Player::player_count = 0;

void Player::Setup(Team* assigned_team)
{
	if (team != nullptr) throw std::string("Attempt to reassign Player team using Setup");

	team = assigned_team;
}

Team* Player::GetTeam()
{
	if (team != nullptr)
	{
		return team;
	}

	throw std::string("Attempt to get unemployed player's team");

	return nullptr;
}

std::string Player::GetName()
{
	return name;
}
