#ifndef EFFECTS_CUBE_H
#define EFFECTS_CUBE_H

#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include "effect.h"

namespace effects
{
    /**
     * Cube is an effect that draws a 3d rotating cube onto the screen.
     */
    class Cube : public Effect
    {
        public:
            /**
             * Construct a new Cube instance.
             *
             * @param window a reference to the render window to draw onto
             */
            Cube(sf::RenderWindow &window);

            /**
             * Destroy this Cube instance.
             */
            ~Cube();

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
            /** Rotation angle. */
            float angle_;

            /** The cube face textures. */
            sf::Texture cube_texture_;
    };
}

#endif
