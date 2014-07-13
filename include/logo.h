#ifndef EFFECTS_LOGO_H
#define EFFECTS_LOGO_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "effect.h"

namespace effects
{
    /**
     * Logo is an effect that renders a sprite onto the screen in a fixed
     * position.
     */
    class Logo : public Effect
    {
        public:
            /**
             * Construct a new logo instance.
             *
             * @param window a reference to the render window to draw onto
             * @param msg the logo message to be displayed
             */
            Logo(sf::RenderWindow &window, const std::string &msg);

            /**
             * Destroy this logo instance.
             */
            ~Logo();

            /**
             * Update the logo effect.
             *
             * @param elapsed the time elapsed since the last update
             */
            void update(sf::Time elapsed) override;

            /**
             * Draw the logo.
             */
            void draw() override;
        private:
            /** The path to the logo font. */
            static const std::string FONT_PATH;

            /** The font to be used. */
            sf::Font font_;

            /** The text to be drawn. */
            sf::Text text_;
    };
}

#endif
