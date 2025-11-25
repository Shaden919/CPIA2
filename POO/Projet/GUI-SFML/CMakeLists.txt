cmake_minimum_required(VERSION 3.10)
project("Main")

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Liste des fichiers sources
set(SOURCES
    src/main.cpp
)

# Création de l'exécutable
add_executable(exe ${SOURCES})

# Find and link SFML (graphics, window and system modules)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if (SFML_FOUND)
    target_include_directories(exe PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
    # Some SFML CMake packages provide imported targets (SFML::Graphics),
    # others only expose library names. Try imported targets first, fallback
    # to plain library names if they are not available.
    if (TARGET SFML::Graphics)
        target_link_libraries(exe PRIVATE SFML::Graphics SFML::Window SFML::System)
    else()
        target_link_libraries(exe PRIVATE sfml-graphics sfml-window sfml-system)
    endif()
else()
    message(FATAL_ERROR "SFML not found. Install SFML development packages or set SFML_DIR.")
endif()