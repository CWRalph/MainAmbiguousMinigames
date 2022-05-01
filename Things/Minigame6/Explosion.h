#pragma once
#include "pch.h"

class Explosion
{
private:
	Vector2 position = {0.0f,0.0f};
	string key = "Explosion";
	int radius = 30;
	bool active = false;

public:
	Explosion(){};
	bool getActive() { return active; }
	int getRadius() { return radius; }
	~Explosion(){};
};

