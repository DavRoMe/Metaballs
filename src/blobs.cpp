#include "blobs.h"

using namespace std;

Blob::Blob(float x, float y, int width, int height) : MobileObj(x, y) {
  SetBndrs(width, height);
  radius = IntRandom(20, 70);

  SetVelocity(IntRandom(-8, 8), IntRandom(-8, 8));
  if(GetXvel() == 0) SetXvel(1);
  if(GetYvel() == 0) SetYvel(-1);

  circle.setRadius(radius / 2);
  circle.setFillColor(sf::Color::Transparent);
  circle.setOutlineThickness(-3);
  circle.setOutlineColor(sf::Color::White);
}

Blob::Blob(sf::Vector2f pos, int width, int height) : MobileObj(pos) {
  SetBndrs(width, height);
  radius = IntRandom(20, 70);

  SetVelocity(IntRandom(-8, 8), IntRandom(-8, 8));
  if(GetXvel() == 0) SetXvel(1);
  if(GetYvel() == 0) SetYvel(-1);

  circle.setRadius(radius / 2);
  circle.setFillColor(sf::Color::Transparent);
  circle.setOutlineThickness(-3);
  circle.setOutlineColor(sf::Color::White);
}

/// /////////////////////////////////////////////////

void Blob::SetBndrs(int width, int height) {
  bounceW = width;
  bounceH = height;
}

void Blob::ShowCircle(sf::RenderWindow& w) {
  circle.setPosition(GetXpos() - radius / 2, GetYpos() - radius / 2);
  w.draw(circle);
}

void Blob::Update() {
  SetPosition(GetPosition() + GetVelocity());

  if(GetXpos() > bounceW || GetXpos() < 0)
    SetXvel(-1 * GetXvel());
  if(GetYpos() > bounceH || GetYpos() < 0)
    SetYvel(-1 * GetYvel());
}
