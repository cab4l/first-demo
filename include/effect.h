#ifndef EFFECTS_EFFECT_H
#define EFFECTS_EFFECT_H

#include <SFML/Graphics.hpp>

namespace effects
{
    /**
     * An Effect represents a visual artifact that can be drawn to 
     * the screen, and may change its visual representation over time.
     */
    class Effect
    {
        public:
            /**
             * Construct a new effect.
             *
             * @param window a reference to the window that the effect will 
             *        render onto
             */
            Effect(sf::RenderWindow &window)
                : window_(window)
            {};

            /**
             * Destroy this effect instance.
             */
            virtual ~Effect() 
            {};

            /**
             * Update the effect given an amount of time passed since the last
             * update.
             *
             * @param elapsed the amount of time since the last update
             * @return void
             */
            virtual void update(sf::Time elapsed) = 0;

            /**
             * Draw the effect in its current state.
             *
             * @return void
             */
            virtual void draw() = 0;
        protected:
            /** The window that the effect will render onto. */ 
            sf::RenderWindow &window_;
    };
}

#endif
