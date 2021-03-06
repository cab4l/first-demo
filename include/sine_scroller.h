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
            /** The text font. */
            sf::Font font_;

            /** Sin wave input arguments. */
            double arg1_, arg2_, arg3_;

            /** the x restart point. */
            double restart_point_;

            /** The rotation angle. */
            double delta_angle_;

            /** The characters containing the message. */
            std::vector<std::shared_ptr<sf::Text>> characters_;
    };
}

#endif
