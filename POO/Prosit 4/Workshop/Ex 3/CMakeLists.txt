cmake_minimum_required(VERSION 3.10)
project("Ex 3")

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## Use target-specific include directories. Make the local `include/`
## directory private to this target so it won't leak to other targets
## and so this target will prefer its own `voiture.hpp`.

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
    src/moto.cpp
    src/voiture.cpp
    src/station.cpp
)

add_executable(exe ${SOURCES})

target_include_directories(exe PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
