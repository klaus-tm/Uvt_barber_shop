cmake_minimum_required(VERSION 3.22)
project(proiect_pp_comun)

set(CMAKE_CXX_STANDARD 14)

include_directories(common/classes)

add_executable(proiect_pp_comun
        common/classes/Comanda.cpp
        common/classes/Comanda.h
        common/classes/Oferte.cpp
        common/classes/Oferte.h
        common/classes/Orar.cpp
        common/classes/Orar.h
        common/files/Comanda_nou.txt
        common/files/Oferte.txt
        student1.cpp
        student2.cpp)
