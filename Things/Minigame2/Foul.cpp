#include "pch.h"
#include "Foul.h"

void Foul::Draw()
{
	// Regulates the occurance of a frame change in the players animation
	DrawTexture(textures["Foul"],this->collider.x, this->collider.y, WHITE);
	DrawRectangleLines(collider.x, collider.y, collider.width, collider.height, RED);

	//cout << DrawRec.y << " " << DrawRec.x << " " << collider.x << " " << collider.y << "Single image height is: " << singleImageHeight << "Single image width is: "<<singleImageWidth << std::endl;
}
