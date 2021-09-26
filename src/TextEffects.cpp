#include "TextEffects.h"

/* Prints out text in a delayed fashion to give the impression of real-time text writing */
void HesitateText(std::istream& in, std::ostream& out, const size_t& delay)
{
	std::string input;
	
	/* Get each line of input from the given istream */
	while (std::getline(in, input))
	{
		/* Iterate through each character of the line, output it; wait for delay */
		for (const char& c : input)
		{
			out << c << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		}
		out << std::endl;
	}
}
