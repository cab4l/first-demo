#ifndef EFFECTS_SINE_SCROLLER_H
#define EFFECTS_SINE_SCROLLER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include "effect.h"

namespace effects
{
    /**
     * SineScroller is an effect that renders text to a moving sine wave. It is
     * a reproduction of a classic effect seen in many oldschool Amiga
     * intros.
     */
    class SineScroller : public Effect
    {
        public:
            /**
             * Construct a new SineScroller instance.
             *
             * @param window a reference to the render window to draw onto
             * @param msg the message to be scrolled
             */
            SineScroller(sf::RenderWindow &window, const std::string &msg);

            /**
             * Destroy this SineScroller instance.
             */
            ~SineScroller();

            /**
             * Update the effect.
             *
             * @param elapsed the elapsed time
             * @return void
             */
            void update(sf::Time elapsed) override;

            /**
             * Draw the scroller.
             */
            void draw() override;
        private:
            /** The font path. */
            static const std::string FONT_PATH;

            /** The text font. */
            sf::Font font_;

            /** The X velocity. */
            double delta_;

            /** The number of horizontal pixels seperating each character. */
            unsigned int characterSpacing_;

            /** The characters containing the message. */
            std::vector<std::shared_ptr<sf::Text>> characters_;
    };
}

#endif
