#ifndef GAME_H

#define GAME_H

#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>
#include "Player.h"
#include "Coach.h"
#include "Team.h"
#include "TextEffects.h"

/* TODO: I think it makes more sense that the *game* initializes players and coaches rather than the teams doing so.
 * Possibly implement AddCoach() and AddPlayer() member functions to this class.
 * Instead of using Team::Setup(), we can create coaches, players, and teams, and then assign them to each other.
 */

class Game
{
public:
	void InitTeams();
	void Run();
private:
	void Shutdown();
	std::vector<Team*> teams;
	std::vector<Player*> player_database;
	std::vector<Coach*> coach_database;
	const size_t MAX_TEAM_COUNT = 32;
};

#endif
