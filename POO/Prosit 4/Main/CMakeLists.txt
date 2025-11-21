cmake_minimum_required(VERSION 3.10)
project("Main")

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
    src/CLpoint.cpp
    src/CLpoint3D.cpp
    src/parcour.cpp
    src/parcour2D.cpp
    src/parcour3D.cpp
)

# Création de l'exécutable
add_executable(exe ${SOURCES})