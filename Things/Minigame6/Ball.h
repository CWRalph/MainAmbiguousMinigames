#pragma once
#include "pch.h"
extern unordered_map<string, Texture2D> textures;

class Ball
{
 public:
  Vector2 speed = {0.0f,0.0f};
  Rectangle rectangle;
  bool active = false;
  Ball(Vector2 pos,float speedx,float speedy) 
  {
    rectangle.x = pos.x;
    rectangle.y = pos.y;
    rectangle.width = textures["pick"].width;
    rectangle.height = textures["pick"].height;
    speed.x = speedx;
    speed.y = speedy;
  }
  void UpdatePosition();

  Rectangle& getCollider() { return rectangle; }
  bool getActive() { return active; }
  void setActive(bool condition) { active = condition; }
  void Draw();
  ~Ball(){};
};

