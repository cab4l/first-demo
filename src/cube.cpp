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
        : Effect(window), angle_(1.0f)
    {
        glClearDepth(1.f);
        glClearColor(0.3f, 0.3f, 0.3f, 0.f);
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.f, 1.f, 1.f, 300.f);
    }

    Cube::~Cube()
    {

    }

    void Cube::update(sf::Time elapsed)
    {
        window_.popGLStates();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);

        angle_ = elapsed.asMilliseconds() * 0.1f;
        glRotatef(angle_ * 50, 1.f, 0.f, 0.f);
        glRotatef(angle_ * 30, 0.f, 1.f, 0.f);
        glRotatef(angle_ * 90, 0.f, 0.f, 1.f);
        window_.pushGLStates();
    }

    void Cube::draw()
    {
        window_.popGLStates();
        glBegin(GL_QUADS);
        glColor3i(0,1,1);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f, -50.f);
        glVertex3f( 50.f, -50.f, -50.f);

        glColor3f(0,0,1);
        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f( 50.f, 50.f, 50.f);
        glVertex3f( 50.f, -50.f, 50.f);

        glColor3f(1,0,1);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(-50.f, -50.f, 50.f);

        glColor3f(0,1,0);
        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, 50.f);
        glVertex3f(50.f, -50.f, 50.f);

        glColor3f(1,1,0);
        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f( 50.f, -50.f, -50.f);
        glVertex3f( 50.f, -50.f, 50.f);

        glColor3f(1,0,0);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f, 50.f);

        glEnd();
        window_.pushGLStates();
    }
}
