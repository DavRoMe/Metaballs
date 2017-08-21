#ifndef PHYSICAL_H_INCLUDED
#define PHYSICAL_H_INCLUDED

#include "vec2op.h"

class MobileObj {
private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    float maxSpeed;
public:
    MobileObj(sf::Vector2f pos);
    MobileObj(sf::Vector2f pos, float speed);
    MobileObj(float x, float y);
    MobileObj(float x, float y, float speed);

    sf::Vector2f GetPosition();
    float GetXpos();
    float GetYpos();
    sf::Vector2f GetVelocity();
    float GetXvel();
    float GetYvel();
    float GetSpeed();

    void SetPosition(sf::Vector2f pos);
    void SetPosition(float x, float y);
    void SetXpos(float x);
    void SetYpos(float y);
    void SetVelocity(sf::Vector2f vel);
    void SetVelocity(float x, float y);
    void SetXvel(float x);
    void SetYvel(float y);
    void SetMaxSpeed(float maxSpeed);
    void Update();
};


#endif // PHYSICAL_H_INCLUDED
