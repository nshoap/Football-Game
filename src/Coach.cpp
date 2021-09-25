#include "Coach.h"

Coach::Coach()
{
	/* This needs to be restructured into randomly generated focus area coaches; not all being offense. */
	focus = CoachFocus::OFFENSE;

	if (focus == CoachFocus::OFFENSE)
	{
		name = "Offensive Guru";
	} else name = "Retire Already";

}
