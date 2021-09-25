#ifndef COACH_H

#define COACH_H

#include <string>

enum class CoachFocus
{
	OFFENSE,
	DEFENSE,
	SPECIAL
};

class Coach
{
public:
	Coach();
private:
	std::string name;
	size_t rating;
	CoachFocus focus;
};

#endif
