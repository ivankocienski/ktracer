cmake_minimum_required (VERSION 2.6)

ENABLE_LANGUAGE(C)
find_package (SDL REQUIRED)

project (ktracer)

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
)

#message (STATUS "${SRC}" )

link_libraries(
    ${SDL_LIBRARY}
)

add_executable(ktracer ${SRC} )
