#ifndef PLAYER_H

#define PLAYER_H

#include <string>

class Player
{
public:
	Player() : name("Default Player " + std::to_string(player_count)) { ++player_count; }
	std::string name;
private:
	static size_t player_count;
};

#endif
