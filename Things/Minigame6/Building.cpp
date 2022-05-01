#include "pch.h"
#include "Building.h"

void Building::Draw()
{
	DrawTexture(textures["lock"], rectangle.x,rectangle.y,WHITE);
}
