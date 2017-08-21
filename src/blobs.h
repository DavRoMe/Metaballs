#ifndef BLOBS_H_INCLUDED
#define BLOBS_H_INCLUDED

#include <physical.h>
#include <aleatorio.h>
#include <SFML/Graphics.hpp>

class Blob : public MobileObj {
private:
  int radius;
  int bounceW, bounceH;
  sf::CircleShape circle;
public:
  Blob(float x, float y, int width, int height);
  Blob(sf::Vector2f pos, int width, int height);
  void SetBndrs(int width, int height);
  void ShowCircle(sf::RenderWindow& w);
  void Update();
};

#endif // BLOBS_H_INCLUDED
