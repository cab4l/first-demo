# Define cmake version
cmake_minimum_required(VERSION 2.8)

# Project name
project(first-demo)

# Project variables
set(PROJ_INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJ_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJ_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(PROJ_RESOURCE_DIR ${PROJECT_SOURCE_DIR}/resources)
set(EXECUTABLE_NAME "first-demo")

# CMake settings
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJ_OUTPUT_DIR})

# Header files
set(HEADER_FILES 
    ${PROJ_INC_DIR}/cube.h
    ${PROJ_INC_DIR}/deco.h
    ${PROJ_INC_DIR}/demo.h
    ${PROJ_INC_DIR}/dumb.h
    ${PROJ_INC_DIR}/effect.h
    ${PROJ_INC_DIR}/logo.h
    ${PROJ_INC_DIR}/mod_music.h
    ${PROJ_INC_DIR}/sine_scroller.h
    ${PROJ_INC_DIR}/starfield.h
    ${PROJ_INC_DIR}/star.h
    ${PROJ_INC_DIR}/utility.h
    ${PROJ_INC_DIR}/resources.h
)

# Source files
set(PROJ_SOURCES 
    ${PROJ_SRC_DIR}/cube.cpp
    ${PROJ_SRC_DIR}/deco.cpp
    ${PROJ_SRC_DIR}/demo.cpp
    ${PROJ_SRC_DIR}/logo.cpp
    ${PROJ_SRC_DIR}/main.cpp
    ${PROJ_SRC_DIR}/mod_music.cpp
    ${PROJ_SRC_DIR}/sine_scroller.cpp
    ${PROJ_SRC_DIR}/star.cpp
    ${PROJ_SRC_DIR}/starfield.cpp
    ${PROJ_SRC_DIR}/utility.cpp
    ${PROJ_SRC_DIR}/cube_texture.cpp
    ${PROJ_SRC_DIR}/chiptune.cpp
    ${PROJ_SRC_DIR}/font.cpp
)

# Compile options
include_directories(${PROJ_INC_DIR})
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_definitions(-Wall)
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_definitions(-Wall -Os)
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

# Detect OpenGL
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
endif()

# Detect SFML 2
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

# Detect libDUMB
find_package(DUMB)
if(DUMB_FOUND)
    include_directories(${DUMB_INCLUDE_DIR})
endif()

# Add the executable target
add_executable(${EXECUTABLE_NAME} ${PROJ_SOURCES})

# Link libraries
target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
target_link_libraries(${EXECUTABLE_NAME} ${DUMB_LIBRARIES})

# Install the target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${PROJ_OUTPUT_DIR})
