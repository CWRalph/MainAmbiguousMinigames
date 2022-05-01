#include "pch.h"
#include "Pig.h"

extern float dt;
extern bool moveable;
extern Pig* selected;

void Pig::UpdatePosition()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && moveable)
	{
		if (CheckCollisionPointRec(GetMousePosition(), position))
		{
			position.x -= 5;
			moveable = false;
			selected = this;
		}
	}
	else
	{
		position.x += speed * dt;
	}
}

void Pig::Draw()
{
	// Regulates the occurance of a frame change in the players animation
	playerAnimRate += dt;
	if (playerAnimRate >= 0.072f)
	{
		if (DrawRec.x >= (2 * singleImageWidth))
		{
			DrawRec.x = 0.f;
		}
		else
		{
			DrawRec.x += singleImageWidth;
		}
		playerAnimRate = 0;
	}

	DrawTextureRec(textures["Pig"], DrawRec, { this->position.x, this->position.y }, WHITE);
	DrawTexture(textures["Grinder"], 20, 750, WHITE);
}