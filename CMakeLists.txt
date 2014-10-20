cmake_minimum_required (VERSION 2.6)

# this gives us warnings about fishy code (-Wall)
#  and symbol tables (-dynamic) and gdb support (-g)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -dynamic -g")

# makefile will print out what it is doing
set(CMAKE_VERBOSE_MAKEFILE ON)

# a hack for SDL
ENABLE_LANGUAGE(C)

# SDL. only this for now
find_package (SDL REQUIRED)

# our exe name
project (ktracer)

# source files. sure, there's a better way of doing this
set (SRC
  src/application.cc
  src/camera.cc
  src/film.cc
  src/main.cc
  src/material.cc
  src/plane.cc
  src/ray.cc
  src/scene-object.cc
  src/scene.cc
  src/sky.cc
  src/sphere.cc
  src/vector3.cc
  src/window.cc
  src/matrix4.cc
  src/matrix3.cc
  src/operations.cc
)

link_libraries(
    ${SDL_LIBRARY}
)

add_executable(ktracer ${SRC} )
