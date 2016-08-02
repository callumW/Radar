cmake_minimum_required (VERSION 2.6)
project (Radar C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

file (GLOB SRC_FILES src/*.c)

add_executable (Radar ${SRC_FILES})

find_library (SDL_LIBRARY NAMES SDL2 PATHS /Library/Framworks )

if (SDL_LIBRARY)
    target_link_libraries (Radar ${SDL_LIBRARY})
endif()
