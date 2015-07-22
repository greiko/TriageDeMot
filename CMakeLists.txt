cmake_minimum_required(VERSION 3.2)
project(tri)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(main ${SOURCE_FILES} gestionStatistique.c gestionStatistique.h main.c listeChaine.h listeChaine.c)