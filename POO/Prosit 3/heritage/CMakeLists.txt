cmake_minimum_required(VERSION 3.10)
project("heritage")

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
    src/personnage.cpp
    src/guerrier.cpp
    src/magicien.cpp
)

# Création de l'exécutable
add_executable(exe ${SOURCES})