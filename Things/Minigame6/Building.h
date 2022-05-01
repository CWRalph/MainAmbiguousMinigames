#include "pch.h"

extern unordered_map<string, Texture2D> textures;


class Building
{
private:
	Rectangle rectangle;
	Color color = GRAY;
public:
	Building(float x, float y)
	{
		rectangle.x = x;
		rectangle.y = y;
		rectangle.width = textures["lock"].width;
		rectangle.height = textures["lock"].height;
	}
	Rectangle& getCollider() { return rectangle; }
	void setColor(Color c) { color = c; }
	void Draw();
	~Building() {};
};

