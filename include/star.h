#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>

class Star
{
    public:
        Star(sf::Uint16 x, sf::Uint16 y );
        sf::Uint16 getXPos();
        sf::Uint16 getYPos() const;
        void addYPos(sf::Uint16 dy);
        void addXPos(sf::Uint16 dx);
    private:
        sf::Uint16 x_pos_;
        sf::Uint16 y_pos_;
};

#endif
