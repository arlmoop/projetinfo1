cmake_minimum_required(VERSION 3.29)
project(projetinfo1 C)

set(CMAKE_C_STANDARD 23)

add_executable(projetinfo1 main.c
        menu.c
        mouvementpions.c
        mouvementbarriere.c
        header.h)
