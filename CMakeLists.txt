cmake_minimum_required(VERSION 3.2)
project(tri)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES testListeChaine.c)
add_executable(triage ${SOURCE_FILES} gestionStatistique.c gestionStatistique.h testListeChaine.c listeChaine.h listeChaine.c)