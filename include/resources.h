#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <cstdint>

namespace resources
{
    /**
     * The textures to be rendered on the cube faces.
     */
    extern std::vector<std::uint8_t> cube_tex[6]; 

    /**
     * The chiptune track to be played in the background.
     */
    extern std::vector<std::uint8_t> chiptune_xm;

    /**
     * The font to use throughout the demo
     */
    extern std::vector<std::uint8_t> font;
}

#endif
