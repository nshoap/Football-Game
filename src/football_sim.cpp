#include <cstdio>
#include <string>
#include <sstream>

class Player {
public:
	Player() : name("Default Player") {}
	std::string name;		
};

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

		if (ss.fail() || player_count <= 0) throw std::string("Error: Failed to read in unsigned integer value for roster size");
		players = new Player[player_count];

		/* Iterate through the dynamically allocated player array and assign names */
		for (i = 0; i < player_count; ++i)
		{
			players[i].name = players[i].name + std::string(" " + std::to_string(i));
		}

		/* Iterate through the array and print out information */
		for (i = 0; i < player_count; ++i)
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
