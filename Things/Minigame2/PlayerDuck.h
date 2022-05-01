#pragma once
#include "pch.h"
enum Direction { RIGHT,LEFT };
extern float dt;
extern unordered_map<string, Texture2D> textures;


class Controls
{
	int right;
	int left;
	int jump;
	int hold;
	int down;

public:
	Controls(const int& r, const int& l, const int& j, const int& h, const int& d) :
		right(r), left(l), jump(j), hold(h),down(d) {}
	Controls(const Controls& c) { jump = c.jump; left = c.left;	right = c.right; hold = c.hold,down = c.down;
	}
	~Controls() {}

	void SetJumpkey(const int& key) { jump = key; }
	void SetRightKey(const int& key) { right = key; }
	void SetLeftKey(const int& key) { left = key; }
	void SetHoldKey(const int& key) { hold = key; }
	void SetDownKey(const int& key) { down = key; }

	const int& GetDownkey() const { return down; }
	const int& GetHoldkey() const { return hold; }
	const int& GetJumpkey() const { return jump; }
	const int& GetRightKey() const { return right; }
	const int& GetLeftKey() const { return left; }
};


class PlayerDuck
{
private:
	Rectangle collider;
	Rectangle DrawRec;
	Rectangle DrawRecFly;
	Controls controls;
	Direction direction = LEFT;

	string key = "PlayerDuck";

	float playerAnimRate = 0;
	float gravity = 840.f;
	float verticalVel = 0.f;
	float horizontalVel = 0.f;
	float singleImageWidth = ((float)textures[key].width) / 9;
	float singleImageHeight = ((float)textures[key].height) / 2;

	bool canJump;

public:
	PlayerDuck(const float x, const float y, const int& ku, const int& kr, const int& kl,const int&hold, const int& down);
	void Setposition(const float& x, const float& y);
	void CheckInput();
	const Rectangle& getCollider()  const { return collider; }
	void resetRec(float x, float y);
	void flyingRec();
	void Draw();
};

