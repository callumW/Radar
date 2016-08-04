cmake_minimum_required (VERSION 2.8)
project (Radar C)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

file (GLOB SRC_FILES src/*.c)

#copy media folder into build directory if we are building outside of source
if (NOT CMAKE_CURRENT_BINARY_DIR EQUAL CMAKE_CURRENT_SOURCE_DIR)
    file (GLOB MEDIA_FILES "media/*")
    file (COPY ${MEDIA_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/media")
endif (NOT CMAKE_CURRENT_BINARY_DIR EQUAL CMAKE_CURRENT_SOURCE_DIR)
add_executable (Radar ${SRC_FILES})

#find_library (SDL_LIBRARY NAMES SDL2 SDL PATHS
#    /Library/Framworks
#    C:/SDL2)

find_package (SDL REQUIRED)
find_package (OpenGL REQUIRED)

include_directories (${SDL_INCLUDE_DIR})
target_link_libraries (Radar ${SDL_LIBRARY})
target_link_libraries (Radar ${OPENGL_LIBRARY})
