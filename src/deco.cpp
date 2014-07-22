#include <stdexcept>

#include "deco.h"
#include "utility.h"

namespace effects
{
    Deco::Deco(sf::RenderWindow &window)
        : Effect(window), border_colour_(sf::Color(100, 20, 100))
    {
        auto window_size = window.getSize();
        auto thickness = window_size.y / 60.0f;

        sf::RectangleShape border(sf::Vector2f(window_size.x, thickness)); 
        border.setFillColor(border_colour_);

        // Top border
        borders_.push_back(border);

        // Bottom border
        border.setPosition(0, window_size.y - thickness);
        borders_.push_back(border);
    }

    Deco::~Deco()
    {}

    void Deco::update(sf::Time elapsed)
    {}

    void Deco::draw()
    {
        window_.pushGLStates();
        for (const auto &border : borders_)
        {
            window_.draw(border);
        }
        window_.popGLStates();
    }
}
