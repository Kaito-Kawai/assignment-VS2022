#include "Character.h"

Character::Character(int attack)
{
	this->attack = attack;
}

Character::~Character()
{
}

int Character::getAttack()
{
	return attack;
}
