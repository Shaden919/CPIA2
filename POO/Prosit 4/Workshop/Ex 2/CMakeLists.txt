cmake_minimum_required(VERSION 3.10)
project("Ex 2")

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("Ex 2" public include)

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
    src/instrument.cpp
    src/piano.cpp
    src/saxophone.cpp
)

# Création de l'exécutable
add_executable(exe ${SOURCES})