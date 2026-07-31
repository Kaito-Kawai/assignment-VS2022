#pragma once

#include <memory>

#include "Character.h"

class Team
{
public:
	Team();

	void setName(const char* name);
	const char* getName();
	int getPower();
	int getTotalAttack();
	Character* getCharacter(int number);
	void takeDamage(int damage);
	bool isDefeated();

private:
	const char* name;
	int power;
	std::unique_ptr<Character> sword;
	std::unique_ptr<Character> wizard;
	std::unique_ptr<Character> summoner;
};
