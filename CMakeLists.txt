cmake_minimum_required(VERSION 3.31)
project(AlgoritmosOrdenacao)

set(CMAKE_CXX_STANDARD 14)

include_directories(funcoes)
include_directories(funcoes/insertion_sort)
include_directories(funcoes/merge_sort)

add_executable(AlgoritmosOrdenacao
        .idea/.gitignore
        .idea/AlgoritmoDeOrdenacao.iml
        .idea/c_cpp_properties.json
        .idea/editor.xml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        funcoes/insertion_sort/insertion_sort.c
        funcoes/insertion_sort/insertion_sort.h
        funcoes/merge_sort/merge_sort.c
        funcoes/merge_sort/merge_sort.h
        funcoes/lista_encadeada.c
        funcoes/lista_encadeada.h
        main.c)
