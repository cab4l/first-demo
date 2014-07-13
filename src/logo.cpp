#include <stdexcept>

#include "logo.h"
#include "utility.h"

using namespace utility;

namespace effects
{
    // Static initialisation
    const std::string Logo::FONT_PATH = resourcePath("font/november.ttf");

    Logo::Logo(sf::RenderWindow &window, const std::string &msg)
        : Effect(window) 
    {
        if (!font_.loadFromFile(FONT_PATH))
        {
            throw std::runtime_error("Failed to load: " + FONT_PATH);
        }

        auto window_size = window.getSize();

        text_.setFont(font_);
        text_.setCharacterSize(window_size.x / 20.0f);
        text_.setString(msg);

        auto logo_size = text_.getLocalBounds();
        text_.setOrigin(logo_size.width / 2, logo_size.height / 2);
        text_.setPosition(window_size.x / 2, window_size.y / 10); 
    }

    Logo::~Logo()
    {}

    void Logo::update(sf::Time elapsed)
    {}

    void Logo::draw()
    {
        window_.draw(text_);
    }
}
