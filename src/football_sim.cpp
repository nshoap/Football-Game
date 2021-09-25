#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Player.h"

constexpr int TEXT_HESITATION = 50;

int main(int argc, char** argv)
{
	size_t i;
	int player_count;
	Player* players;
	std::istringstream ss;
	std::ifstream fin;
	std::string str;

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

		/* Open our start menu text; display it char-by-char */
		/* This prints out the text char-by-char using a wait period defined by the const TEXT_HESITATION. */
		/* It's cool that you've got this working, but should probably move text-effects to their own function so they can be called with any text. */
		/* TODO: Move to a specific function, make text hesitation a variable */

		fin.open("txt/welcome.txt");
		while (std::getline(fin, str))
		{
			for (const char& c : str)
			{
				std::cout << c << std::flush;
				std::this_thread::sleep_for(std::chrono::milliseconds(TEXT_HESITATION));
		
			}
			std::cout << std::endl;
		}

	} catch (const std::string& e) {
		/* Print out error message and exit the program */
		printf("%s\n", e.c_str());
		return -1;
	}

	return 0;
}
