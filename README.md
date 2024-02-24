# 3DVectorRendering
Basic c++ implementation of 3D rendering a vector object using mathematics.

## Dependencies
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

Disclaimer; the libraries are already present inside the external folder to use on windows. If you would like to
run this project on Linux or MacOSX be sure to download the correct development libraries and install them on
your system.

## Getting started
1. Clone this project.
2. Open the project with your ide of choice (support for CMake is required).
3. Run the project with the root `CMakeLists.txt` file! :tada:

## Testing
This project includes the test framework [Catch2](https://github.com/catchorg/Catch2). To use this framework and start testing, 
change `set(RUN_TESTS FALSE)` to `set(RUN_TESTS TRUE)` inside the `CMakeLists.txt` file.
