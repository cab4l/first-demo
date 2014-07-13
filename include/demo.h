#ifndef DEMO_H
#define DEMO_H

#include <vector>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "effect.h"
#include "mod_music.h"

/**
 * Demo represents the demoscene intro instance. Its responsibilities 
 * include initialisation, management of the demo loop, and cleanup of 
 * resources once the demo has finished.
 */
class Demo
{
    public:
        /**
         * Construct a new demo instance.
         *
         * @param title the title to be displayed on the window
         * @param video_mode the rendering mode to use
         */
        Demo(const std::string &title, const sf::VideoMode &video_mode);

        /**
         * Destroy this demo instance.
         * This method will free any dynamically acquired memory.
         */
        ~Demo();

        /**
         * Run the demo.
         * This method implements a looping mechanism to update the display.
         */
        void run();
    private:
        /**
         * Initialise resources required to run the demo.
         */
        void init();

        /**
         * Update the scene.
         *
         * @param elapsed the elapsed time since the last update
         */
        void update(const sf::Time elapsed);

        /**
         * Draw the scene.
         */
        void draw();

        /**
         * Cleanup any acquired resources.
         */
        void cleanup();

        /** A flag to specify if vertical sync should be enabled. */
        static const bool VSYNC_ENABLED;

        /** The filepath to the music to be played during the demo. */
        static const std::string MUSIC_PATH;

        /** The text to be displayed by the sine scroller. */
        static const std::string WAVE_TEXT;

        /** The text to be displayed by the logo. */
        static const std::string LOGO_TEXT;

        /** The title to be displayed on the window. */
        const std::string &title_;

        /** The video mode. */
        const sf::VideoMode &video_mode_;

        /** The display window. */
        sf::RenderWindow window_;

        /** The music stream. */
        ModMusic music_;

        /** A clock used to regulate the update loop. */
        sf::Clock clock_;

        /** A vector of loaded effects. */
        std::vector<std::unique_ptr<effects::Effect>> effects_;
};

#endif
