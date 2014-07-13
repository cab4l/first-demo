#ifndef EFFECTS_STARFIELD_H
#define EFFECTS_STARFIELD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "effect.h"
#include "star.h"

namespace effects
{
    /**
     * Starfield is an effect that simulates a parralox scrolling starfield.
     */
    class Starfield : public Effect
    {
        public:
            /**
             * Create a new Starfield instance.
             *
             * @param window a reference to the render window to draw to
             */
            Starfield(sf::RenderWindow &window);

            /**
             * Update the starfield.
             *
             * @param elapsed the elapsed time
             */
            void update(sf::Time elapsed) override;

            /**
             * Draw the effect.
             */
            void draw() override;
        private:
            /** Destroy dead stars. */
            void remove_dead_stars();

            /** Add new stars as required. */
            void add_new_stars();

            /** Move the stars. */
            void move_stars();
            
            /** Update the stars texture. */
            void update_stars_texture();

            /** Maximum star sizes. */
            int max_small_stars_, max_medium_stars_, max_large_stars_;

            /** Target window size. */
            sf::Vector2u window_size_;

            /** Random generators for x and y dimensions. */
            std::default_random_engine random_engine_x_, random_engine_y_;

            /** Uniform distributions for x and y axis. */
            std::uniform_int_distribution<int> distribution_x_, distribution_y_;
            
            /** Stars. */
            std::vector<Star> small_stars_, medium_stars_, large_stars_;

            /** Star images */
            sf::Image stars_image_, small_star_image_, medium_star_image_, large_star_image_;

            /** The star texture. */
            sf::Texture stars_texture_;

            /** The star sprite. */
            sf::Sprite stars_sprite_;
    };
}

#endif


