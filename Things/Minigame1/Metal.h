#pragma once
#include "pch.h"
extern unordered_map<string, Texture2D> textures;
extern float dt;

#define M_Gravity 90

class Metal
{
	Rectangle* collider;
	string* textureKey;

public:
	Metal(const float& x, const float& y, const string& key) 
		: textureKey(new string(key)), collider(new Rectangle({x + textures[key].width * 0.2f, y + textures[key].height * 0.2f, (float)textures[key].width * 0.6f, (float)textures[key].height * 0.6f })) {}

	Metal(const Metal& m)
	{
		textureKey = new string(*m.textureKey);
		collider = new Rectangle(*m.collider);	
	}

	~Metal()
	{
		if (collider)
		{
			delete collider;
			collider = nullptr;
		}
		if (textureKey)
		{
			delete textureKey;
			collider = nullptr;
		}
	}

	void inline Draw() const { DrawTexture(textures[*textureKey], collider->x, collider->y, WHITE); }
	void inline Update(const float& timer)
	{ 
		float t = M_Gravity * (timer + 1) * dt;
		if (t > 10.f) t = 10.f;
		collider->y += t;
		 
	}

	const Rectangle& GetCollider() const { return *collider; }

	
};