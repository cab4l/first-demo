#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace utility
{ 
    /**
     * Get the absolute path to a resource.
     * @param name the name of the resource
     * @return the absolute path to the named resource
     */
    const std::string resourcePath(const std::string &name);
}

#endif
