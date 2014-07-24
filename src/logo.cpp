#include <stdexcept>

#include "logo.h"
#include "utility.h"

#include "resources.h"

using namespace utility;
using namespace resources;

namespace effects
{
    Logo::Logo(sf::RenderWindow &window, const std::string &msg)
        : Effect(window) 
    {
        if (!font_.loadFromMemory(&font[0], font.size()))
        {
            throw std::runtime_error("Failed to load font");
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
        window_.pushGLStates();
        window_.draw(text_);
        window_.popGLStates();
    }
}
