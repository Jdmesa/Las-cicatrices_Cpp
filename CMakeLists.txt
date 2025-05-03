cmake_minimum_required(VERSION 3.30)
project(Las_cicatrices_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Las_cicatrices_Cpp main.cpp
        Ecosistema/nodo.cpp
        Ecosistema/mapa.cpp
        Ecosistema/mapa.h
        criaturaPrueba.cpp
        criaturaPrueba.h
        criatura.cpp
        criatura.h
        Ecosistema/ecosistema.cpp
        Ecosistema/ecosistema.h
        dragon.cpp
        dragon.h
        Atributos/fantasma.cpp
        Atributos/fantasma.h
        hada.cpp
        hada.h
        Atributos/volador.cpp
        Atributos/volador.h
)
