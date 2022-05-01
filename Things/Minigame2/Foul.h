#pragma once
#include "pch.h"
extern unordered_map<string, Texture2D> textures;
extern float dt;

class Foul
{
private:
	Rectangle collider;

	float playerAnimRate = 0;

	string key = "Foul";
public:
	Foul(const float xval,const float yval)
	{
		collider = { xval, yval, (float)textures["Foul"].width, (float)textures["Foul"].height };
	}
	const Rectangle& getCollider()  const { return collider; }
	void Draw();
	~Foul() {};
};

