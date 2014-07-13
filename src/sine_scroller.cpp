#include <stdexcept>
#include <memory>

#include "sine_scroller.h"
#include "utility.h"

using namespace utility;

namespace effects
{
    // Static initialisation
    const std::string SineScroller::FONT_PATH = resourcePath("font/text.ttf");

    SineScroller::SineScroller(sf::RenderWindow &window, const std::string &msg)
        : Effect(window)
    {
        if (!font_.loadFromFile(FONT_PATH))
        {
            throw std::runtime_error("Failed to load " + FONT_PATH); 
        }

        auto window_size = window.getSize();
        characterSpacing_ = window_size.x/50;
        delta_ = window_size.x / 100.0f;
        int count = 0;

        for(auto c : msg)
        {
            count+=characterSpacing_;
            std::shared_ptr<sf::Text> character(new sf::Text(c, font_));
            character->setPosition(count, window_size.y * 0.75); 
            characters_.push_back(std::move(character));
        }

    }

    SineScroller::~SineScroller()
    {}

    void SineScroller::update(sf::Time elapsed)
    {
        int characterSkip = 0;

        for (auto &character : characters_)
        {
           character->move(-5, 0); 
           if (character->getPosition().x < 0)
           {
               auto rightPadding = (-character->getPosition().x) + characterSkip * characterSpacing_;
               characterSkip+=characterSpacing_;
               character->setPosition(1024 + rightPadding, 768 * 0.75);
           }
 
        }
    }

    void SineScroller::draw()
    {
        for (auto &character : characters_)
        {
            window_.draw(*character);
        }
    }

}
