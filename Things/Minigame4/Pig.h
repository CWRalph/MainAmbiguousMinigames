#pragma once
#include "pch.h"
extern unordered_map<string, Texture2D> textures;
extern float dt;

class Pig
{
public:
  Rectangle position;
  Rectangle DrawRec;
  float speed = 100;
  float singleImageWidth = ((float)textures["Pig"].width) / 3;
  float playerAnimRate = 0;



  //GetMousePosition



  Pig(float x, float y, float speedx):speed(speedx)
  {
    DrawRec = {0, 0, singleImageWidth, ((float)textures["Pig"].height) };
    position = { x,y,singleImageWidth,((float)textures["Pig"].height) };
  }
  void UpdatePosition();

  Rectangle getPosition() { return position; }
  void Draw();
  ~Pig() {};
};


