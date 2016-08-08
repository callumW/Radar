#Radar v0.1.0 STATUS: Work-In-Progress i.e. do NOT use
##Description
Radar is a submarine sim game, played using a radar-type ui, made in C.
##License
Radar is licensed under the [MIT License](https://opensource.org/licenses/MIT).
See [LICENSE](LICENSE)
##Tools/Libraries/Languages used
-  [SDL](http://www.libsdl.org) & [openGL](https://www.opengl.org/)
-  [CMake](https://www.cmake.org)

##System Requirements
- [CMake](https://www.cmake.org)
- GCC and some form of auto-make-system (may work with other compilers)
- [SDL](http://www.libsdl.org)
- [openGL](https://www.opengl.org/) (will likely already be installed)
- a dedicated GPU, i.e. a graphics card, unless your CPU is fast enough

##Installation (TO DO: Make this better!!)
1. Run CMake in the Radar directory (Radar/) where the file [CMakeLists.txt]
(CMakeLists.txt) lives. **Note:** It is highly recommended you make the build
directory outside of the source directory.
2. Navigate to the build directory and run your chosen make system / open it
with your chosen IDE.
3. Before running the compiled program make sure to copy the SDL.dll into the
same directory as the executable (on windows only).

##Tested Systems:
- Windows:
  + MinGW (32 bit)
  + Visual Studio 11 (32 bit)
- Linux:
- OS X:
  + Unix Make and Clang
