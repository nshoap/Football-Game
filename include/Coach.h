#ifndef COACH_H

#define COACH_H

#include <string>

class Team;

enum class CoachFocus
{
	OFFENSE,
	DEFENSE,
	SPECIAL
};

class Coach
{
public:
	Coach();
	void Setup(Team* assigned_team);
	Team* GetTeam();
	std::string GetName();
private:
	std::string name;
	size_t rating;
	CoachFocus focus;
	Team* team = nullptr;
};

#endif
