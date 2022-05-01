#pragma once
extern float dt;
extern unordered_map<string, Texture2D> textures;

class Duck
{
private:
	Rectangle collider;
	Rectangle DrawRec;

	bool offscreen = false;
	float singleImageWidth = ((float)textures["Duck"].width) / 3;
	float singleImageHeight = ((float)textures["Duck"].height) / 3;


	float playerAnimRate = 0;

	string key = "Duck";
public:
	Duck(const float yval)
	{
		collider = { -50, yval, singleImageWidth, singleImageHeight };
		DrawRec = { 0, 0,  (- singleImageWidth)+ 10, singleImageHeight-10};
	}
	void Move();
	const Rectangle& getCollider() const { return collider; }
	bool isOffscreen() { return offscreen; }
	void Draw();
	~Duck(){};
};

