#pragma once
#include <string>
class Sprite {
	std::string name;
	int health;
	int damage;
public:
	Sprite(std::string nm, int hp, int dam);
	~Sprite();
};

