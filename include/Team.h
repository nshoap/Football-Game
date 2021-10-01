#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>
#include "Player.h"
#include "Coach.h"

class Team
{
public:
	void Setup();
	std::string GetName();
	const std::vector<Player*> GetRoster();
	void FillRoster(std::vector<Player*>&);
	void HireCoach(Coach*);
private:
	static size_t team_count;
	std::string name;
	std::vector<Player*> roster;
	Coach* head_coach = nullptr;
};

#endif
