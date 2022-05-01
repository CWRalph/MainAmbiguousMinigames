#pragma once
#include "pch.h"

extern float dt;
extern unordered_map<string, Texture2D> textures;


enum class FM_Direction
{
	Right,
	Left
};

class Player_FM
{
	Rectangle* collider =  new Rectangle();
	Rectangle* sourceRec = new Rectangle();
	FM_Direction* direction = new FM_Direction(FM_Direction::Left);
	float timer = 0;
	void UpdateDelay();

public:
	Player_FM() 
	{
		*collider = { 400.f, 775.f, (float)textures["FM_Player"].width / 9, (float)textures["FM_Player"].height };
		*sourceRec = {0, 0, (float)textures["FM_Player"].width / 9, (float)textures["FM_Player"].height };
	}

	~Player_FM()
	{
		if (collider)
		{
			delete collider;
			collider = nullptr;
		}
		if (sourceRec)
		{
			delete sourceRec;
			sourceRec = nullptr;
		}
		if (direction)
		{
			delete direction;
			direction = nullptr;
		}
	}

	const Rectangle& GetCollider() const { return *collider; }
	const float& GetTimer() const { return timer; }

	void CheckInput();
	void Draw();
};

