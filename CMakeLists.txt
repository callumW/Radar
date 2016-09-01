cmake_minimum_required (VERSION 2.8)
project (Radar CXX)

file (GLOB SRC_FILES "src/*.cpp")

#copy media folder into build directory if we are building outside of source
if (NOT CMAKE_CURRENT_BINARY_DIR EQUAL CMAKE_CURRENT_SOURCE_DIR)
    file (GLOB MEDIA_FILES "media/*")
    file (COPY ${MEDIA_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/media")
endif (NOT CMAKE_CURRENT_BINARY_DIR EQUAL CMAKE_CURRENT_SOURCE_DIR)

# For building release Add WIN32 before ${SRC_FILES}
add_executable (Radar ${SRC_FILES})

set (
    CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package (SDL2 REQUIRED)
find_package (OpenGL REQUIRED)
find_package (SDL2_ttf REQUIRED)
find_package (OpenAL REQUIRED)

include_directories (
    ${SDL2_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${SDL2TTF_INCLUDE_DIR}
    ${OPENAL_INCLUDE_DIR} )

target_link_libraries (
    Radar
    ${SDL2_LIBRARY}
    ${OPENGL_LIBRARY}
    ${SDL2TTFMAIN_LIBRARY}
    ${OPENAL_LIBRARY})
