cmake_minimum_required(VERSION 3.10)
project(Application)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
    src/ListData.cpp
)

# Création de l'exécutable
add_executable(Exercice ${SOURCES})