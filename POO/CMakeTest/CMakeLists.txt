cmake_minimum_required(VERSION 3.10)
project(Calculatrice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Inclure le dossier "include" pour les fichiers .hpp
include_directories(include)

# Définir l’exécutable
add_executable(calculatrice
    src/main.cpp
    src/calcul.cpp
)
