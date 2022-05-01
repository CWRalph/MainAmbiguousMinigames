#include "pch.h"
#include "Ball.h"
extern float dt;
void Ball::UpdatePosition()
{
	rectangle.x += speed.x*dt;
	rectangle.y += speed.y*dt;
	speed.y += 120.f * dt;
}
void Ball::Draw()
{
	if (active) DrawTexture(textures["pick"], rectangle.x, rectangle.y, WHITE);
}
