#include "pch.h"
#include "cPlayer.h"
extern float dt;

void Player::Draw()
{
	DrawRectangle(position.x - size.x / 2, position.y - size.y / 2,size.x, size.y, RED);
  DrawTriangle({ position.x - size.x / 4, position.y - size.y / 4 },{position.x + size.x / 4, position.y + size.y / 4},previousPoint, GRAY);

  // Actual aiming
  DrawTriangle({ position.x - size.x / 4, position.y - size.y / 4 },{ position.x + size.x / 4, position.y + size.y / 4},aimingPoint, DARKBLUE);

  for (auto& i : balls)
  {
    i.Draw();
  }
}

void Player::UpdatePlayer()
{
  //We are aiming at firing quadrant
  if (GetMousePosition().x >= position.x)
  {
    //Distance calculating firepower
    aimingPower = sqrt(pow(position.x - GetMousePosition().x, 2) + pow(position.y - GetMousePosition().y, 2));
    // Calculates the angle via arcsin
    aimingAngle = asin((position.y - GetMousePosition().y) / aimingPower) * RAD2DEG;
    // Point of the screen we are aiming at, GetMouse returns a vector2
    aimingPoint = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      previousPoint = aimingPoint;
      previousPower = aimingPower;
      previousAngle = aimingAngle;
      balls.push_back(Ball(position, cos(previousAngle * DEG2RAD) * previousPower, -sin(previousAngle * DEG2RAD) * previousPower));
      balls[balls.size() - 1].setActive(true);
    }
  }
  short index = 0;
  for (auto& i : balls)
  {
    i.UpdatePosition();
    if (i.getCollider().x > screenWidth) balls.erase(balls.begin() + index);
    else if (i.getCollider().y > screenHeight) balls.erase(balls.begin() + index);
    ++index;
  }
}



bool Player::getBallCollision(Building& build)
{
  short index = 0;
  for (auto& i : balls)
  {
    if (CheckCollisionRecs(i.getCollider(), build.getCollider()))
    {
      cout << i.getCollider().x << " , " << build.getCollider().x << std::endl;
      impactPoint.x = i.getCollider().x;
      impactPoint.y = i.getCollider().y;
      build.setColor(RED);
      balls.erase(balls.begin() + index);
      return true;
    }
    ++index;
  }
  return false;
}
