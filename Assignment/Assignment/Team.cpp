#include "Team.h"

#include "Swordsman.h"
#include "Wizard.h"
#include "Summoner.h"

Team::Team()
{
	name = "";
	power = 300;

	sword = std::unique_ptr<Character>(new Swordsman(35));
	wizard = std::unique_ptr<Character>(new Wizard(40));
	summoner = std::unique_ptr<Character>(new Summoner(25));
}

void Team::setName(const char* name)
{
	this->name = name;
}

const char* Team::getName()
{
	return name;
}

int Team::getPower()
{
	return power;
}

int Team::getTotalAttack()
{
	return sword->getAttack()
		+ wizard->getAttack()
		+ summoner->getAttack();
}

Character* Team::getCharacter(int number)
{
	if (number == 1)
	{
		return sword.get();
	}
	else if (number == 2)
	{
		return wizard.get();
	}
	else if (number == 3)
	{
		return summoner.get();
	}
	else
	{
		return nullptr;
	}
}

void Team::takeDamage(int damage)
{
	power -= damage;

	if (power < 0)
	{
		power = 0;
	}
}

bool Team::isDefeated()
{
	return power <= 0;
}
