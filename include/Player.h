#ifndef PLAYER_H

#define PLAYER_H

#include <string>

class Team;

class Player
{
public:
	Player() : name("Default Player " + std::to_string(player_count)) { ++player_count; }
	void Setup(Team* assigned_team);
	bool ViewOffer(const size_t&);
	Team* GetTeam();
	std::string GetName();
private:
	std::string name;
	static size_t player_count;
	Team* team = nullptr;
};

#endif
