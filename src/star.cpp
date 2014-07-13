#include "star.h"

Star::Star(sf::Uint16 x, sf::Uint16 y)
    : x_pos_(x), y_pos_(y)
{}

sf::Uint16 Star::getXPos()
{
    return x_pos_;
}

sf::Uint16 Star::getYPos() const
{
    return y_pos_;
}

void Star::addXPos(sf::Uint16 dx)
{
    x_pos_+=dx;
}

void Star::addYPos(sf::Uint16 dy)
{
    y_pos_+=dy;
}
