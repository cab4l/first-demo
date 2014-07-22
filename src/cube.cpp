#include <stdexcept>
#include <memory>
#include <math.h>

#include <SFML/OpenGL.hpp>

#include "cube.h"
#include "utility.h"

using namespace utility;

namespace effects
{
    Cube::Cube(sf::RenderWindow &window)
        : Effect(window)
    {
        auto window_size = window_.getSize();

        // Load resources
        for(int i = 1; i <= 6; i++)
        {
            std::unique_ptr<sf::Texture> tex(new sf::Texture);
            std::string texture_path = resourcePath("textures/" + std::to_string(i) + ".png");
            if (!tex->loadFromFile(texture_path))
            {
                throw std::runtime_error("Failed to load: " + texture_path); 
            }
            cube_textures_.push_back(std::move(tex));            
        }

        // GL Init
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glClearDepth(1.f);
        glViewport(0, 0, window_size.x, window_size.y);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat ratio = static_cast<float>(window_size.x / window_size.y);
        glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
    }

    Cube::~Cube()
    {}

    void Cube::update(sf::Time elapsed)
    {
        angle_ += elapsed.asSeconds() * 0.2f;        
    }

    void Cube::draw()
    {
        glClear(GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(angle_ * 50, 1.f, 0.f, 0.f);
        glRotatef(angle_ * 30, 0.f, 1.f, 0.f);
        glRotatef(angle_ * 90, 0.f, 0.f, 1.f);

        int textId = 0;

        sf::Texture::bind(cube_textures_[textId++].get());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f( 50.f, 50.f, -50.f);
            glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, -50.f);
        glEnd();

        sf::Texture::bind(cube_textures_[textId++].get());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, 50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, 50.f);
            glTexCoord2f(1, 1); glVertex3f( 50.f, 50.f, 50.f);
            glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, 50.f);
        glEnd();

        sf::Texture::bind(cube_textures_[textId++].get());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(-50.f, 50.f, 50.f);
            glTexCoord2f(1, 0); glVertex3f(-50.f, -50.f, 50.f);
        glEnd();
 
        sf::Texture::bind(cube_textures_[textId++].get());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(50.f, -50.f, -50.f);
            glTexCoord2f(0, 1); glVertex3f(50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(50.f, 50.f, 50.f);
            glTexCoord2f(1, 0); glVertex3f(50.f, -50.f, 50.f);
        glEnd();
 
        sf::Texture::bind(cube_textures_[textId++].get());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, 50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, -50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(50.f, -50.f, -50.f);
            glTexCoord2f(1, 0); glVertex3f(50.f, -50.f, 50.f);
        glEnd();
 
        sf::Texture::bind(cube_textures_[textId].get());
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, 50.f, 50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(50.f, 50.f, -50.f);
            glTexCoord2f(1, 0); glVertex3f(50.f, 50.f, 50.f);
        glEnd();
    }
}
