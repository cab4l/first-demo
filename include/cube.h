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
            /** The number of faces on a cube. */
            static const int CUBE_FACES;

            /** Rotation angle. */
            float angle_;

            /** The cube face textures. */
            std::vector<sf::Texture> cube_textures_;
    };
}

#endif
