#include <iosfwd>
#include <stdexcept>

#include <SFML/Graphics.hpp>

#include "mod_music.h"
#include "demo.h"
#include "logo.h"
#include "deco.h"
#include "starfield.h"
#include "sine_scroller.h"
#include "cube.h"
#include "utility.h"
#include "resources.h"

using namespace effects;
using namespace utility;
using resources::chiptune_xm;

// Static initialisation
const bool Demo::VSYNC_ENABLED = true;
const std::string Demo::WAVE_TEXT = "Please save the date of July 24th 2015 for the wedding of Michael Scott and Laura Hollier "
                                    "in Newport Pagnell. Formal invitation to follow.";
const std::string Demo::LOGO_TEXT = "save the $(date)";

Demo::Demo(const std::string &title, const sf::VideoMode &video_mode)
    :title_(title), video_mode_(video_mode)
{
    init();
}

Demo::~Demo()
{
    cleanup();
}

void Demo::run()
{
    music_.setLoop(true);
    music_.play();
    while (window_.isOpen())
    {
        sf::Time elapsed = clock_.restart();
        sf::Event event;
        while (window_.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window_.close();
                    break;
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        window_.close();
                    break;
                default:
                    break;
            }
        }

        update(elapsed);
        draw();
    }
}

void Demo::init()
{
    // Create the window
    window_.create(video_mode_, title_, sf::Style::Fullscreen, sf::ContextSettings(32));
    window_.setVerticalSyncEnabled(VSYNC_ENABLED);

    // Music
    if (!music_.openFromMemory(reinterpret_cast<const char*>(&chiptune_xm[0]), chiptune_xm.size()))
    {
        throw std::runtime_error("Failed to load music");
    }

    // Load effects
    effects_.push_back(std::unique_ptr<Effect>(new Starfield(window_)));
    effects_.push_back(std::unique_ptr<Effect>(new Cube(window_)));
    effects_.push_back(std::unique_ptr<Effect>(new Logo(window_, LOGO_TEXT)));
    effects_.push_back(std::unique_ptr<Effect>(new SineScroller(window_, WAVE_TEXT))); 
    effects_.push_back(std::unique_ptr<Effect>(new Deco(window_)));
}

void Demo::update(sf::Time elapsed)
{
    for (const auto& effect : effects_)
    {
        effect->update(elapsed);
    } 
}

void Demo::draw()
{
    window_.clear();
    for (const auto& effect : effects_)
    {
        effect->draw();
    }
    window_.display();
}

void Demo::cleanup()
{}
