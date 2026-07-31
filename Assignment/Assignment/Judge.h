#pragma once

#include "Character.h"
#include "Team.h"

class Judge
{
public:
	void judge
	(
		Character* playerCharacter, int actionSelect,
		Character* enemyCharacter, int enemyaction,
		Team& playerTeam, Team& enemyTeam
	);

private:
	void judgeJob
	(
		Character* attackCharacter,
		Character* guardCharacter,
		Team& attackTeam,
		Team& guardTeam
	);
};
