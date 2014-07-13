#include "utility.h"
#include <unistd.h>
#include <limits.h>
#include <stdexcept>

namespace utility
{ 
    const std::string resourcePath(const std::string &name)
    {
    #ifdef __unix__
        char result[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);

        if (!count)
        {
            throw std::runtime_error("Failed to determine the execution path.");
        }

        std::string path(result, count);

        return path.substr(0, path.find_last_of("\\/") + 1) + name;
    #else
        // We are not using a UNIX like os, just assume that our execution
        // directory is the base of the demo folder.
        return name; 
    #endif
    }
}

