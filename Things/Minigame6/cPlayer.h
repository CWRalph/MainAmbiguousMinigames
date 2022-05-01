#pragma once
#include "pch.h"
#include "Ball.h"
#include "Building.h"
extern unordered_map<string, Texture2D> textures;


class Player
{
private:
  Vector2 position;
  Vector2 size;
  Vector2 aimingPoint;
  Vector2 impactPoint;
  Vector2 previousPoint;

  int aimingAngle=0;
  int aimingPower = 0;
  int previousAngle = 0;
  int previousPower = 0;

  vector<Ball> balls;

  bool isAlive = true;

  string key = "hordePlayer";
public:
  Player(float x, float y) 
  {
    //default
    size = { 40,40 };
    position = { x,y };
    previousPoint = position;
    aimingPoint = position;
    impactPoint = { -100,-100 };
  };

  Vector2 getPosition() { return position; }
  Vector2 getSize() { return size; }
  Vector2 getAimingPoint() { return aimingPoint; }
  Vector2 getPreviousPoint() { return previousPoint; }
  Vector2 getImpactPoint() { return impactPoint; }

  int getBallsSize() { return balls.size(); }
  int getAimingAngle() { return aimingAngle; }
  int getAimingPower() { return aimingPower; }
  int getPreviousAngle() { return previousAngle; }
  int getPreviousPower() { return previousPower; }

  bool getBallCollision(Building& build);

  void UpdatePlayer();
  void Draw();
  ~Player(){};
};

