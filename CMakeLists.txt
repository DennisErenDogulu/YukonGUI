cmake_minimum_required(VERSION 3.28)
project(YukonGUI C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# Set the path to the SDL2 library directory
set(SDL2_PATH "C:/Users/eren/Downloads/SDL2-devel-2.30.2-mingw/SDL2-2.30.2/x86_64-w64-mingw32")

# Set the path to the SDL2_image library directory
set(SDL2_IMAGE_PATH "C:/Users/eren/Downloads/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/x86_64-w64-mingw32")

# Specify the path to SDL2_image library files
set(SDL2_IMAGE_INCLUDE_DIR "${SDL2_IMAGE_PATH}/include")
set(SDL2_IMAGE_LIBRARIES "${SDL2_IMAGE_PATH}/lib/libSDL2_image.dll.a")

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Add SDL2_image include directory to the include directories
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

# Add SDL_image library directory to the include directories
include_directories("C:/Users/eren/Downloads/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/x86_64-w64-mingw32/include/SDL2")

add_executable(YukonGUI src/main.c
        src/Linkedlist.h
        src/Linkedlist.c
        src/controller.c
        src/controller.h
        src/deck.c
        src/deck.h
        src/gameCommands.c
        src/gameCommands.h
        src/view.c
        src/view.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
