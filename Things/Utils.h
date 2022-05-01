#pragma once
#include "pch.h"
extern unordered_map<string, Texture2D> textures;


static int Random(int max = 100, int min = 0, const vector<int>& exclude = {})
{
	++max;
	if (min > 0) --min;
	unsigned int size = exclude.size(), result = 0;
	bool isValid = true;
	do
	{
		isValid = true;
		std::random_device rd;
		std::mt19937 gen(rd());
		int t = gen();
		if (t < 0) t *= -1;
		result = (t % (max - min)) + min;
		for (unsigned i = 0; i < size; i++)
			if (result == exclude[i]) { isValid = false; break; }
	} while (!isValid);

	return result;
}

static void LoadGameTextures()
{
#pragma region Minigame1
	textures.insert({ "mountainBG", LoadTexture("Minigame1/Assests/mountainBG.png") });
	textures.insert({ "FM_Player", LoadTexture("Minigame1/Assests/PlayerSpriteSheet.png") });
	textures.insert({ "Coin", LoadTexture("Minigame1/Assests/Coin.png") });
	textures.insert({ "Battery", LoadTexture("Minigame1/Assests/Battery.png") });
	textures.insert({ "Arsenic", LoadTexture("Minigame1/Assests/Arcenic.png") });
	textures.insert({ "Lead", LoadTexture("Minigame1/Assests/Lead.png") });
	textures.insert({ "Vibranium", LoadTexture("Minigame1/Assests/Vibranium.png") });

#pragma endregion

#pragma region Minigame2
	textures.insert({ "Foul", LoadTexture("Minigame2/Assets/foulMadamas.png") });
	textures.insert({ "Duck", LoadTexture("Minigame2/Assets/Duck.png") });
	textures.insert({ "PlayerDuck",LoadTexture("Silhouette.png") });
	textures.insert({ "PlayerDuckFly",LoadTexture("Minigame2/Assets/FlyingSilhouette.png") });
	textures.insert({ "lakeBG",LoadTexture("Minigame2/Assets/lakeBG.png") });
#pragma endregion

#pragma region Minigame4
	textures.insert({ "PigBG", LoadTexture("Minigame4/Assets/spiritedBG.png") });
	textures.insert({ "Pig", LoadTexture("Minigame4/Assets/pig.png") });
	textures.insert({ "Rope",LoadTexture("Minigame4/Assets/rope.png") });
	textures.insert({ "Grinder", LoadTexture("Minigame4/Assets/meatGrinder.png") });
#pragma endregion
#pragma region Minigame6
	textures.insert({ "lock", LoadTexture("Minigame6/Assets/lock.png") });
	textures.insert({ "pick", LoadTexture("Minigame6/Assets/pick.png") });
#pragma endregion
}