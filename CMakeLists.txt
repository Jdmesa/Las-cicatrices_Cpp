cmake_minimum_required(VERSION 3.30)
project(Las_cicatrices_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Las_cicatrices_Cpp main.cpp
        Ecosistema/nodo.cpp
        Ecosistema/mapa.cpp
        Ecosistema/mapa.h
        Criaturas/criaturaPrueba.cpp
        Criaturas/criaturaPrueba.h
        Atributos/criatura.cpp
        Atributos/criatura.h
        Ecosistema/ecosistema.cpp
        Ecosistema/ecosistema.h
        Criaturas/dragon.cpp
        Criaturas/dragon.h
        Atributos/fantasma.cpp
        Atributos/fantasma.h
        Criaturas/hada.cpp
        Criaturas/hada.h
        Atributos/volador.cpp
        Atributos/volador.h
        Criaturas/enano.cpp
        Criaturas/enano.h
        Atributos/regeneracion.cpp
        Atributos/regeneracion.h
)
