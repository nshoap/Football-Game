#include <cstdio>
#include <string>
#include <sstream>
#include "Player.h"

int main(int argc, char** argv)
{
	size_t i;
	int player_count;
	Player* players;
	std::istringstream ss;

	/* Encapsulate program in try/catch for error checking */
	try {
		/* Throw error if invalid usage */
		if (argc != 2)
		{
			throw std::string("Usage: ./football_sim roster_size");
		}

		/* Open stringstream */
		ss.str(std::string(argv[1]));

		/* Read in player count */
		ss >> player_count;

		/* Throw error if input could not be read or if was negative or zero */
		if (ss.fail() || player_count <= 0) throw std::string("Error: Failed to read in unsigned integer value for roster size");

		/* Dynamically allocate roster */
		players = new Player[player_count];

		/* Iterate through the array and print out information */
		for (i = 0; i < static_cast<size_t>(player_count); ++i)
		{
			printf("Player: %5s\n", players[i].name.c_str());
		}

	} catch (const std::string& e) {
		/* Print out error message and exit the program */
		printf("%s\n", e.c_str());
		return -1;
	}

	return 0;
}
