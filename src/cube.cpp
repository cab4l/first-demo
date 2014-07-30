#include <stdexcept>
#include <math.h>

#include <SFML/OpenGL.hpp>

#include "cube.h"
#include "utility.h"
#include "resources.h"

namespace effects
{
    // Static initialisation
    const int Cube::CUBE_FACES = 6;

    Cube::Cube(sf::RenderWindow &window)
        : Effect(window), angle_(0.0f)
    {
        auto window_size = window_.getSize();

        // Load resources
        for (const auto &texture : resources::cube_tex)
        {
            sf::Texture cube_texture;
            if (!cube_texture.loadFromMemory(&texture[0], texture.size()))
            {
                throw std::runtime_error("Failed to load texture");
            }
            cube_textures_.push_back(cube_texture);
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
        angle_ += elapsed.asSeconds() * 0.5f; 
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

        auto current_texture = cube_textures_.begin();

        sf::Texture::bind(&(*current_texture++));
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f( 50.f, 50.f, -50.f);
            glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, -50.f);
        glEnd();

        sf::Texture::bind(&(*current_texture++));
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, 50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, 50.f);
            glTexCoord2f(1, 1); glVertex3f( 50.f, 50.f, 50.f);
            glTexCoord2f(1, 0); glVertex3f( 50.f, -50.f, 50.f);
        glEnd();

        sf::Texture::bind(&(*current_texture++));
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, -50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(-50.f, 50.f, 50.f);
            glTexCoord2f(1, 0); glVertex3f(-50.f, -50.f, 50.f);
        glEnd();

        sf::Texture::bind(&(*current_texture++));
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(50.f, -50.f, -50.f);
            glTexCoord2f(0, 1); glVertex3f(50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(50.f, 50.f, 50.f);
            glTexCoord2f(1, 0); glVertex3f(50.f, -50.f, 50.f);
        glEnd();

        sf::Texture::bind(&(*current_texture++));
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, -50.f, 50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, -50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(50.f, -50.f, -50.f);
            glTexCoord2f(1, 0); glVertex3f(50.f, -50.f, 50.f);
        glEnd();

        sf::Texture::bind(&(*current_texture++));
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-50.f, 50.f, 50.f);
            glTexCoord2f(0, 1); glVertex3f(-50.f, 50.f, -50.f);
            glTexCoord2f(1, 1); glVertex3f(50.f, 50.f, -50.f);
            glTexCoord2f(1, 0); glVertex3f(50.f, 50.f, 50.f);
        glEnd();
    }
}
