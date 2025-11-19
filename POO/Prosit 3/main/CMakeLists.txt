cmake_minimum_required(VERSION 3.10)
project("main")

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
    src/point.cpp
    src/vector.cpp
    src/segment.cpp
    src/polygone.cpp
    src/cercle.cpp
)

# Création de l'exécutable
add_executable(exe ${SOURCES})