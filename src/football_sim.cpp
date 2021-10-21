#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Game.h"

int main()
{
	Game game;

	/* Encapsulate program in try/catch for error checking */
	try {
		game.Run();

	} catch (const std::string& e) {
		/* Print out error message and exit the program */
		printf("%s\n", e.c_str());
		return -1;
	}

	/* Test comment */

	return 0;
}
