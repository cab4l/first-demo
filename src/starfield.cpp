#include "starfield.h"

namespace effects
{
    Starfield::Starfield(sf::RenderWindow &window)
        : Effect(window)
    {
        window_size_ = window.getSize();

        // Create the star images
        stars_image_.create(window_size_.x, window_size_.y, sf::Color::Black);
        small_star_image_.create(1, 1, sf::Color::White);
        medium_star_image_.create(2, 2, sf::Color::Green);
        large_star_image_.create(4, 4, sf::Color::Red);

        // Populate the star texture and make it pretty
        stars_texture_.loadFromImage(stars_image_);
        stars_texture_.setSmooth(false);

        // Bind the texture to the sprite and set its initial position
        stars_sprite_.setTexture(stars_texture_);
        stars_sprite_.setPosition(0, 0);

        // Seed random distribution for new stars
        distribution_x_ = std::uniform_int_distribution<int>(0, window_size_.x);
        distribution_y_ = std::uniform_int_distribution<int>(0, window_size_.y);
        random_engine_x_.seed(std::time(0));
        random_engine_y_.seed(std::time(0)+24);

        // Determine the maximum number of stars based on the window size,
        // giving preference towards many small stars and less large stars
        int reduce_stars = 8;
        int class_difference = 3;
        max_small_stars_ = (window_size_.x / (reduce_stars * 10)) * (window_size_.y / reduce_stars);
        max_medium_stars_ = (window_size_.x / (reduce_stars * 10 * class_difference)) * 
            (window_size_.y / (reduce_stars * class_difference));
        max_large_stars_ = (window_size_.x / (reduce_stars * 10 * class_difference * class_difference)) * 
            (window_size_.y / (reduce_stars * class_difference));

        // Populate the initial set of stars to be drawn
        while((int)small_stars_.size() <= max_small_stars_)
        {
            small_stars_.push_back(Star(distribution_x_(random_engine_x_), distribution_y_(random_engine_y_)));
        }

        while((int)medium_stars_.size() <= max_medium_stars_)
        {
            medium_stars_.push_back(Star(distribution_x_(random_engine_x_), distribution_y_(random_engine_y_)));
        }

        while((int)large_stars_.size() <= max_large_stars_)
        {
            large_stars_.push_back(Star(distribution_x_(random_engine_x_), distribution_y_(random_engine_y_)));
        }
    }

    void Starfield::update(sf::Time elapsed)
    {
        // Clear the star texture 
        stars_texture_.loadFromImage(stars_image_);

        // Update the starfield
        move_stars();
        remove_dead_stars();
        add_new_stars();
        update_stars_texture();
    }

    void Starfield::update_stars_texture()
    {
        for(std::vector<Star>::iterator it = small_stars_.begin(); it != small_stars_.end(); ++it)
        {
            stars_texture_.update(small_star_image_, it->getXPos(), it->getYPos());
        }

        for(std::vector<Star>::iterator it = medium_stars_.begin(); it != medium_stars_.end(); ++it)
        {
            stars_texture_.update(medium_star_image_, it->getXPos(), it->getYPos());
        }

        for(std::vector<Star>::iterator it = large_stars_.begin(); it != large_stars_.end(); ++it)
        {
            stars_texture_.update(large_star_image_, it->getXPos(), it->getYPos());
        }

    }

    void Starfield::move_stars()
    {
        for_each(small_stars_.begin(), small_stars_.end(), [&](Star &star)
        {
            star.addXPos(-1);
        });
        
        for_each(medium_stars_.begin(), medium_stars_.end(), [&](Star &star)
        {
            star.addXPos(-2);
        });
        
        for_each(large_stars_.begin(), large_stars_.end(), [&](Star &star)
        {
            star.addXPos(-4);
        });
    }

    void Starfield::remove_dead_stars()
    {
        small_stars_.erase(remove_if(small_stars_.begin(), small_stars_.end(), [&](Star &star)
        {
            return (star.getXPos() <= 0);
        }), small_stars_.end());

        medium_stars_.erase(remove_if(medium_stars_.begin(), medium_stars_.end(), [&](Star &star)
        {
            return (star.getXPos() <= 0);
        }), medium_stars_.end());

        large_stars_.erase(remove_if(large_stars_.begin(), large_stars_.end(), [&](Star &star)
        {
            return (star.getXPos() <= 0);
        }), large_stars_.end());
    }

    void Starfield::add_new_stars()
    {
        while((int)small_stars_.size() <= max_small_stars_)
        {
            small_stars_.push_back(Star(window_size_.x, distribution_y_(random_engine_y_)));
        }

        while((int)medium_stars_.size() <= max_medium_stars_)
        {
            medium_stars_.push_back(Star(window_size_.x, distribution_y_(random_engine_y_)));
        }

        while((int)large_stars_.size() <= max_large_stars_)
        {
            large_stars_.push_back(Star(window_size_.x, distribution_y_(random_engine_y_)));
        }
    }

    void Starfield::draw()
    {
        window_.draw(stars_sprite_);
    }
}
