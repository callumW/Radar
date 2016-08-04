cmake_minimum_required (VERSION 2.6)
project (Radar C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

file (GLOB SRC_FILES src/*.c)

add_executable (Radar ${SRC_FILES})

#find_library (SDL_LIBRARY NAMES SDL2 SDL PATHS
#    /Library/Framworks
#    C:/SDL2)

find_package (SDL REQUIRED)

include_directories (${SDL_INCLUDE_DIR})
target_link_libraries (Radar ${SDL_LIBRARY})
