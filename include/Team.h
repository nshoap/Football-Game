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
private:
	static size_t team_count;
	const size_t MAX_ROSTER_SIZE = 53;
	std::string name;
	std::vector<Player*> roster;
	Coach* head_coach;
};

#endif
