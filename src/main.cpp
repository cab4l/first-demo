#include <iostream>
#include <sstream>
#include <getopt.h>

#include <SFML/Graphics.hpp>

#include "demo.h"

/** Begin the demo. */
void begin();

/** Display usage information. */
void display_usage(const char *exec_name);

/** Display the version number of the demo. */
void display_version();

/** Constants. */
static const std::string DEMO_NAME = "First-Demo";
static const unsigned int WINDOW_WIDTH = 1024;
static const unsigned int WINDOW_HEIGHT = 768;
static const double VERSION = 0.1;

int main(int argc, char *argv[])
{
    char *exec_name = argv[0];
    int option, option_index;

    static struct option long_options[] = 
    {
        {"help",0,0,'h'},
        {"version",0,0,'v'},
        {0,0,0,0}
    };

    while ((option = getopt_long(argc, argv, "hv", long_options, 
                    &option_index)) != -1)
    {
        switch(option)
        {
            case 'h':
                display_usage(exec_name);
                exit(EXIT_SUCCESS);
            case 'v':
                display_version();
                exit(EXIT_SUCCESS);
            default:
                display_usage(exec_name);
                exit(EXIT_FAILURE);
        }
    }

    begin();
    return EXIT_SUCCESS;
}

void begin()
{
    std::cout << "Welcome to the demo!" << std::endl;
    Demo demo(DEMO_NAME, sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT));
    demo.run();
}

void display_usage(const char *exec_name)
{
    std::stringstream ss;
    ss << "Usage: " << exec_name << " [OPTIONS]" << std::endl;
    ss << "Options:" << std::endl;
    ss << "\t-h, --help\tDisplay this help message" << std::endl;
    ss << "\t-v, --version\tDisplay the version information" << std::endl;
    std::cout << ss.str();
}

void display_version()
{
    std::stringstream ss;
    ss << DEMO_NAME << " " << VERSION << std::endl;
    ss << "Copyright (C) 2014 Mike Scott" << std::endl;
    ss << "This software is provided under the MIT license" << std::endl;
    std::cout << ss.str();
}

