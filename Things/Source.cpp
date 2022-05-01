#include "pch.h"

#include "Minigame2/Duck.h"
#include "Minigame2/Foul.h"
#include "Minigame2/PlayerDuck.h"
#include "doublyLinkedList.h"
#include "Minigame1/Player.h"
#include "Minigame1/Metal.h"
#include "Utils.h"
#include "Minigame4/Pig.h"
#include "Minigame5/ffr.h"
#include "Minigame6/cPlayer.h"
#include "Minigame6/Enemy.h"

extern unordered_map<string, Texture2D> textures{};

extern float dt = 0;
extern bool moveable = true;
extern Pig* selected = nullptr;
int main()
{
	InitWindow(screenWidth, screenHeight, "Thlngs");
	InitAudioDevice();
	LoadGameTextures();
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	GameScreen currentScreen = GameScreen::FIREWALL;

	unordered_map<string, Music> music;
	unordered_map<string, Sound> sounds;
	
#pragma region Minigame2Values
	//Minigame 2 Values
	vector<Duck> ducks;
	vector<Foul> foul;
	int foulCounter = 0;
	short index;
	vector<PlayerDuck> players{ PlayerDuck(350.f, 350.f, KEY_W, KEY_D, KEY_A,KEY_SPACE,KEY_S) };
#pragma endregion
#pragma region Minigame1Values

	DoublyLinkedList<Metal> metals;
	string temp = "";
	const string m_Keys[5] = { "Coin", "Lead", "Arsenic", "Vibranium", "Battery" };
	short size = 0;
	for (short i = 0; i < 10 * 90; i += 90)
	{
		temp = m_Keys[Random(4)];
		metals.push_back(Metal(Random(screenWidth - textures[temp].width), (float)(-i), temp));
	}
#pragma endregion
#pragma region Minigame6Values
	vector<Building> buildings;
	buildings.push_back(Building(200, 800));
	buildings.push_back(Building(400, 800));
	buildings.push_back(Building(600, 800));
	buildings.push_back(Building(200, 200));
	buildings.push_back(Building(400, 200));
	buildings.push_back(Building(600, 200));
	int buildingIndex = 0;

	Player player(50, 400);
#pragma endregion
#pragma region Minigame4Values
	vector<Pig> piggies;
	for (int i = 150; i < 500; i += 25)
	{
		piggies.push_back(Pig(i, 800, 20));
	}
#pragma endregion

	ffrPlayer fplayer;
	ffrBullets bullets;

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
	
	Player_FM player_FM;

	while (!WindowShouldClose())
	{	
		dt = GetFrameTime();
		for (auto& it : music)
		{
			if (IsMusicStreamPlaying(it.second))
			{
				UpdateMusicStream(it.second);
				break;
		    }
		}

		switch (currentScreen)
		{
		case GameScreen::TITLE:
			break;
		case GameScreen::FALLINGMETAL:
		{
			if (player_FM.GetTimer() > 300.f) currentScreen = GameScreen::PULLEDPORK;
			player_FM.CheckInput();
			if (Random(50000 * dt) < (int)player_FM.GetTimer())
			{
				temp = m_Keys[Random(4)];
				metals.push_back(Metal((float)Random(screenWidth - textures[temp].width), -250.f, temp));
			}
			size = (short)metals.size();
			for (short i = 0; i < size; i++)
			{
				if (CheckCollisionRecs(player_FM.GetCollider(), metals[i].GetCollider()))
					currentScreen = GameScreen::FRANCE;
				metals[i].Update(player_FM.GetTimer());
				if (metals[i].GetCollider().y > screenHeight + 300.f) metals.erase(i);
			}
				
		} break;		

		case GameScreen::PULLEDPORK:
			for (auto& i : piggies)
			{
				i.UpdatePosition();
			}
			moveable = true;
			break;
		case GameScreen::FIREWALL:
			player.UpdatePlayer();
			buildingIndex = 0;
			for (auto& i : buildings)
			{
				if(player.getBallCollision(i)) buildings.erase(buildings.begin() + buildingIndex);
				else i.Draw();
				++buildingIndex;
				if(buildings.size() == 0) currentScreen = GameScreen::PULLEDPORK;
			}
			break;
		case GameScreen::DUCK:
			if (Random(50000) * dt < 1)
			{
				ducks.push_back(Duck(Random(screenHeight - 30, 30)));
			}
			if (Random(100000) * dt < 1)
			{
				foul.push_back(Foul(Random(screenWidth - 30, 30),Random(screenHeight - 30, 30)));
			}
			index = 0;
			for (auto& i : ducks)
			{
				i.Move();
				if (i.isOffscreen()) ducks.erase(ducks.begin() + index);
				++index;
			}
			for (auto& i : players)
			{
				i.CheckInput();
				for (const auto& d : ducks)
				{
					if (CheckCollisionRecs(i.getCollider(), d.getCollider()))
					{
						currentScreen = GameScreen::FALLINGMETAL;
					}
				}
				index = 0;
				for (const auto& f : foul)
				{
					if (CheckCollisionRecs(i.getCollider(), f.getCollider()))
					{
						foul.erase(foul.begin() + index);
						++foulCounter;
					}
					if(foulCounter >= 3)currentScreen = GameScreen::FALLINGMETAL;
					++index;
				}
			}
			break;
		case GameScreen::LOW_KEY:
			break;
		case GameScreen::MICROSOFT:
			break;
		case GameScreen::LOCKSMITH:
			break;
		case GameScreen::MICROCHIPS:
			break;
		case GameScreen::SHAKE_SPEAR:
			break;
		case GameScreen::FRANCE:
				fplayer.update();
				bullets.spawnEdge(dt);
				bullets.update(dt);
			break;
		}

		BeginDrawing();
		DrawFPS(5, 5);
		ClearBackground(RAYWHITE);

		switch (currentScreen)
		{
		case GameScreen::TITLE:
			break;
		case GameScreen::FALLINGMETAL:
		{
			DrawTexture(textures["mountainBG"], 0, 0, WHITE);
			player_FM.Draw();
			for (short i = 0; i < size; i++)
				metals[i].Draw();
		} break;	
		case GameScreen::PULLEDPORK:
			DrawTexture(textures["PigBG"], 0, 0, WHITE);
			for (auto& i : piggies)
			{
				i.Draw();
				if (i.getPosition().x > screenWidth) currentScreen = GameScreen::DUCK;
			}
			if (selected)
			{
				DrawLineBezier({500,670 }, { selected->getPosition().x + 50,selected->getPosition().y + 40 }, 2.0f, BROWN);
			}

			break;
		case GameScreen::FIREWALL:
			player.Draw();
			break;
		case GameScreen::DUCK:
			DrawTexture(textures["lakeBG"],-400,0,WHITE);
			for (auto& i : ducks)
			{
				i.Draw();
			}
			for (auto& i : players)
			{
				i.Draw();
			}
			for (auto& i : foul)
			{
				i.Draw();
			}
			break;
		case GameScreen::LOW_KEY:
			break;
		case GameScreen::MICROSOFT:
			break;
		case GameScreen::LOCKSMITH:
			break;
		case GameScreen::MICROCHIPS:
			break;
		case GameScreen::SHAKE_SPEAR:
			break;
		case GameScreen::FRANCE:
			fplayer.draw();
			bullets.draw();
			break;
		}

		EndDrawing();
	}

	StopSoundMulti();

	for (auto& it : sounds)
	{
		if (IsSoundPlaying(it.second))
			StopSound(it.second);
		UnloadSound(it.second);
	}

	for (auto& it : music)
	{
		if (IsMusicStreamPlaying(it.second))
			StopMusicStream(it.second);
		UnloadMusicStream(it.second);
	}

	CloseAudioDevice();
	CloseWindow();
	return 0;
}