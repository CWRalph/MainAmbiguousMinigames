#include "pch.h"

extern float dt;
class ffrMain {
	int lol = 5;


};


class ffrBullet {
public:
	//float xpos, ypos = 0;
	Vector2 org = { 1.0f,1.0f };
	Vector2 pos = { 1.0f,1.0f };
	Vector2 vel = { 1.0f,1.0f };
	Vector2 acc = { 1.0f,1.0f };

	Color colour = DARKGREEN;
	float size = 20;

	void draw();
	void update(float dt);

	ffrBullet(float x, float y, float xv, float yv, int s, Color c) {
		pos = { x,y };
		vel = { xv, yv };
		size = s;
		colour = c;
	}
};
void ffrBullet::draw() {
	DrawCircleV(pos, size, colour);
}
void ffrBullet::update(float dt) {
	//pos = { pos.x + acc.x * vel.x * dt, pos.y + acc.y *vel.y * dt };
	//pos = { org.x + 100 * dt, org.y + 100 * dt };
	pos.x += vel.x * dt;
	pos.y += vel.y * dt;
}

class ffrBullets {
	vector<ffrBullet> bullets;

public:
	void randSpawn(float dt);
	void spawn(float xpos, float ypos, float yv, float xv, int size, Color c);
	void update(float dt);
	void draw();
	Vector2 randEdgePos();
	void spawnEdge(float dt);
};

void ffrBullets::spawnEdge(float dt) {
	Vector2 pVec = randEdgePos();
	float yvel = GetRandomValue(-500, 500);
	float xvel = GetRandomValue(-500, 500);
	int size = GetRandomValue(5, 50);

	spawn(pVec.x, pVec.y, yvel, xvel, size, RED);

}

Vector2 ffrBullets::randEdgePos() {
	Vector2 r;

	int t = GetRandomValue(0, 3);
	if (t == 0) { r.x = 0; r.y = rand() % screenHeight; }
	if (t == 1) { r.x = screenWidth; r.y = rand() % screenHeight; }
	if (t == 2) { r.y = 0; r.x = rand() % screenWidth; }
	if (t == 3) { r.y = screenHeight; r.x = rand() % screenWidth; }

	return r;
}

void ffrBullets::randSpawn(float dt) {
	float xpos = GetRandomValue(0, screenHeight);
	float ypos = GetRandomValue(0, screenWidth);
	float yvel = GetRandomValue(-500, 500);
	float xvel = GetRandomValue(-500, 500);

	int size = GetRandomValue(10, 100);
	Color c = RED;
	//Color[3] cl = [BLUE, WHITE, RED];

	spawn(xpos, ypos, yvel, xvel, size, c);
}


void ffrBullets::spawn(float xpos, float ypos, float yv, float xv, int size, Color c) {
	bullets.push_back(ffrBullet(xpos, ypos, yv, xv, size, c));
}
void ffrBullets::update(float dt) {
	for (auto& i : bullets) {
		i.update(dt);
	}
}
void ffrBullets::draw() {
	for (auto& i : bullets) {
		i.draw();
	}
}


class ffrPlayer {
public:
	int xpos;
	int ypos;

	int size = 10;
	//Color colour;
	int health;


	Color colour = DARKBLUE;
	Vector2 pos = { -100.0f,-100.0f };

	void draw(void);
	void update();
};

void ffrPlayer::draw(void) {
	DrawCircleV(pos, size, colour);
}
void ffrPlayer::update() {
	pos = GetMousePosition();
}
