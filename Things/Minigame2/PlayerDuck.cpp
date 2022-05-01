#include "pch.h"
#include "PlayerDuck.h"

PlayerDuck::PlayerDuck(const float x, const float y, const int& ku, const int& kr, const int& kl,const int& hold, const int& down)
  : controls(kr, kl, ku, hold,down)
{
  collider = { x, y, singleImageWidth, singleImageHeight };
  DrawRec = { 0, 0,  singleImageWidth, singleImageHeight};
  DrawRecFly = { 0, 0,  (float)textures["PlayerDuckFly"].width, (float)textures["PlayerDuckFly"].height };
}


void PlayerDuck::Setposition(const float& x, const float& y)
{
   collider.x = x - collider.width;
   collider.y = y - collider.height;
   DrawRec.x = x - (DrawRec.width * 0.5f);
   DrawRec.y = y - (DrawRec.height * 0.5f);
}

void PlayerDuck::CheckInput()
{
  //Passive - vert velocity is reduced by gravity
  //Passive - horizontal velocity is reduced to 0 unless a key is pressed where it will then increase it to a max
  if (IsKeyPressed(controls.GetJumpkey()))
  {
    if (canJump)
    {
      key = "PlayerDuckFly";
      verticalVel = -500;
      canJump = false;
      flyingRec();
    }
    gravity = 200.f;
  }
  if (IsKeyReleased(controls.GetJumpkey())) gravity = 840.f;


  //This block is pasively slowing down the player's horizontal velocity to 0
  //If the player is holding down a key they should be accelerating faster, therefore 
  //The increase in velocity of 480 is greater than the passive slowdown of 240
  if (IsKeyDown(controls.GetLeftKey()))
  {
    if (direction != LEFT) 
    { 
      DrawRec.width = -(DrawRec.width);
      DrawRecFly.width = -(DrawRecFly.width);
      direction = LEFT;
    }
    horizontalVel -= 480 * dt;
    if (horizontalVel < -240) horizontalVel = -240;
  }
  else if (IsKeyDown(controls.GetRightKey()))
  {
    if (direction != RIGHT)
    {
      DrawRec.width = -(DrawRec.width);
      DrawRecFly.width = -(DrawRecFly.width);
      direction = RIGHT;
    }
    horizontalVel += 480 * dt;
    if (horizontalVel > 240) horizontalVel = 240;
  }
  else
  {
    //Player is not trying to move left or right
    if (horizontalVel > 0)
    {
      if (horizontalVel - 240 * dt < 0) horizontalVel = 0;
      else horizontalVel -= 240 * dt;
    }
    else if (horizontalVel < 0)
    {
      if (horizontalVel + 240 * dt > 0) horizontalVel = 0;
      else horizontalVel += 240 * dt;
    }
  }
  this->collider.x += horizontalVel * dt;

  float floory = screenHeight - 100;
  if (IsKeyDown(controls.GetHoldkey())) verticalVel = 0;
  else if(IsKeyDown(controls.GetDownkey())) verticalVel += 4*gravity * dt;
  else verticalVel += gravity * dt;


  if (this->collider.y + this->collider.height + verticalVel * dt >= floory)
  {
    resetRec(collider.x,this->collider.y = floory - this->collider.height);
    canJump = true;
    key = "PlayerDuck";
  }
  else if(IsKeyUp(controls.GetHoldkey())) this->collider.y += verticalVel * dt;
}

void PlayerDuck::resetRec(float x, float y)
{
  collider = { x, y, singleImageWidth, singleImageHeight };
}

void PlayerDuck::flyingRec()
{
  collider.height = abs(DrawRecFly.height);
  collider.width = abs(DrawRecFly.width);
}

void PlayerDuck::Draw()
{
  // Regulates the occurance of a frame change in the players animation
  playerAnimRate += dt;
  if (key == "PlayerDuck")
  {
    if (playerAnimRate >= 0.072f)
    {
      if (DrawRec.y >= (singleImageHeight) && DrawRec.x >= (8 * singleImageWidth))
      {
        DrawRec.y = 0.f;
        DrawRec.x = 0.f;
      }
      else
      {
        if (DrawRec.x >= (8 * singleImageWidth))
        {
          DrawRec.x = 0.f;
          DrawRec.y += singleImageHeight;
        }
        else DrawRec.x += singleImageWidth;
      }
      playerAnimRate = 0;
    }
    DrawTextureRec(textures[key], DrawRec, { this->collider.x, this->collider.y }, WHITE);
  }
  else
  {
    DrawTextureRec(textures["PlayerDuckFly"], DrawRecFly, { this->collider.x, this->collider.y }, WHITE);
  }
  DrawRectangleLines(collider.x, collider.y, collider.width, collider.height, RED);
  //draws the duck and the distance traveled
  //cout << DrawRec.y << " " << DrawRec.x << " " << collider.x << " " << collider.y << "Single image height is: " << singleImageHeight << "Single image width is: "<<singleImageWidth << std::endl;
}