#include "Coach.h"

Coach::Coach()
{
	/* This needs to be restructured into randomly generated focus area coaches; not all being offense. */
	focus = CoachFocus::OFFENSE;

	if (focus == CoachFocus::OFFENSE)
	{
		name = "Offensive Guru";
	} else name = "Retire Already";

}

void Coach::Setup(Team* assigned_team)
{
	/* Check if already employed */
	if (team != nullptr) throw std::string("Attempt to change coach employer using Setup");

	team = assigned_team;
}

Team* Coach::GetTeam()
{
	/* Return team if employed */
	if (team != nullptr)
	{
		return team;
	}

	throw std::string("Attempt to get unemployed coach's team");

	return nullptr;
}

std::string Coach::GetName()
{
	return name;
}
