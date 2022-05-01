#include "pch.h"
#include "Duck.h"

void Duck::Move()
{
	if (collider.x > screenWidth) offscreen = true;
	else collider.x += 100 * dt;
}

void Duck::Draw()
{
	// Regulates the occurance of a frame change in the players animation
	playerAnimRate += dt;
	if (playerAnimRate >= 0.072f)
	{
		if (DrawRec.y >= (2 * singleImageHeight) && DrawRec.x >= (2 * singleImageWidth))
		{
			DrawRec.y = 0.f;
			DrawRec.x = 0.f;
		}
		else
		{
			if (DrawRec.x >= (2 * singleImageWidth))
			{
				DrawRec.x = 0.f;
				DrawRec.y += singleImageHeight;
			}
			else DrawRec.x += singleImageWidth;
		}
		playerAnimRate = 0;
	}
	//draws the duck and the distance traveled
	if(!offscreen)DrawTextureRec(textures["Duck"], DrawRec, {this->collider.x, this->collider.y}, WHITE);
	//cout << DrawRec.y << " " << DrawRec.x << " " << collider.x << " " << collider.y << "Single image height is: " << singleImageHeight << "Single image width is: "<<singleImageWidth << std::endl;
}
