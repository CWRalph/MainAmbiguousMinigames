#pragma once
#include "pch.h"

class Enemy
{
private:
	Vector2 position;
	int health;
	string key = "Enemy";
public:
	Enemy(){};
	~Enemy(){};
};

