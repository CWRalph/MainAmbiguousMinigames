#include "pch.h"
#include "Player.h"

#define FM_SPD

#define FM_SPD 180
float delay = 0;

void Player_FM::UpdateDelay()
{
	delay += dt;
	if (delay >= 0.072f)
	{
		sourceRec->x += textures["FM_Player"].width * 0.11111f;
		delay = 0;
	}
	if (sourceRec->x >= textures["FM_Player"].width)
		sourceRec->x = 0;
}

void Player_FM::CheckInput()
{
	float g = 1;
	if (IsKeyDown(KEY_LEFT_SHIFT))
		g = 2;
	if (IsKeyDown(KEY_D))
	{	
		*direction = FM_Direction::Right;
		this->UpdateDelay();
		collider->x += FM_SPD * dt * g;
		if (collider->x + collider->width > screenWidth)
			collider->x = screenWidth - collider->width;
	}
	if (IsKeyDown(KEY_A))  
	{
		*direction = FM_Direction::Left;
		this->UpdateDelay();
		collider->x -= FM_SPD * dt * g;
		if (collider->x < 0) collider->x = 0;
		
	}
	if (IsKeyUp(KEY_A) && IsKeyUp(KEY_D))
		sourceRec->x = 0;
	timer += dt;
}

void Player_FM::Draw()
{
	if (*direction == FM_Direction::Left && sourceRec->width < 0) sourceRec->width *= -1;
	else if (*direction == FM_Direction::Right && sourceRec->width > 0) sourceRec->width *= -1;
	
	DrawTextureRec(textures["FM_Player"], *sourceRec, { collider->x, collider->y }, WHITE);
}
