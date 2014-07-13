#ifndef EFFECTS_DECO_H
#define EFFECTS_DECO_H

#include <SFML/Graphics.hpp>

#include "effect.h"

namespace effects
{
    /**
     * Deco is an effect that adds general decoration objects to the screen.
     */
    class Deco : public Effect
    {
        public: 
            /**
             * Construct a new deco instance.
             *
             * @param window a reference to the render window to draw onto
             */
            Deco(sf::RenderWindow &window);

            /**
             * Destroy this deco instance.
             */
            ~Deco();

            /**
             * Update the effect.
             *
             * @param elapsed the elapsed time
             */
            void update(sf::Time elapsed) override;

            /**
             * Draw the effect.
             */
            void draw() override;
        private:
            /** Window borders. */
            std::vector<sf::RectangleShape> borders_;

            /** The border colour. */
            sf::Color border_colour_;
    };
}

#endif
