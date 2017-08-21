#include "physical.h"

using namespace std;

MobileObj::MobileObj(sf::Vector2f pos) {
  SetPosition(pos);
  SetMaxSpeed(0);
}

MobileObj::MobileObj(sf::Vector2f pos, float speed) {
  SetPosition(pos);
  SetMaxSpeed(speed);
}

MobileObj::MobileObj(float x, float y) {
  SetPosition(x, y);
  SetMaxSpeed(0);
}

MobileObj::MobileObj(float x, float y, float speed) {
  SetPosition(x, y);
  SetMaxSpeed(speed);
}

///Getters/////////////////////////////////////////////////

sf::Vector2f MobileObj::GetPosition() {
  return this->pos;
}
float MobileObj::GetXpos() {
  return pos.x;
}
float MobileObj::GetYpos() {
  return pos.y;
}
///////////////////////////////////////////////////////
sf::Vector2f MobileObj::GetVelocity() {
  return this->vel;
}
float MobileObj::GetXvel() {
  return vel.x;
}
float MobileObj::GetYvel() {
  return vel.y;
}
///////////////////////////////////////////////////////
float MobileObj::GetSpeed() {
  return getMagnitude(this->vel);
}

///Setters/////////////////////////////////////////////////

void MobileObj::SetPosition(sf::Vector2f pos) {
  this->pos = pos;
}
void MobileObj::SetPosition(float x, float y) {
  pos.x = x;
  pos.y = y;
}
void MobileObj::SetXpos(float x) {
  pos.x = x;
}
void MobileObj::SetYpos(float y) {
  pos.y = y;
}
///////////////////////////////////////////////////////
void MobileObj::SetVelocity(sf::Vector2f vel) {
  this->vel = vel;
}
void MobileObj::SetVelocity(float x, float y) {
  vel.x = x;
  vel.y = y;
}
void MobileObj::SetXvel(float x) {
  vel.x = x;
}
void MobileObj::SetYvel(float y) {
  vel.y = y;
}
////////////////////////////////////////////////////////
void MobileObj::SetMaxSpeed(float maxSpeed) {
  this->maxSpeed = maxSpeed;
}
////////////////////////////////////////////////////////
void MobileObj::Update() {
  if(maxSpeed != 0 && getMagnitude(vel) > abs(maxSpeed)) {
    vel = setMagnitude(vel, maxSpeed);
  }
  pos += vel;
}
