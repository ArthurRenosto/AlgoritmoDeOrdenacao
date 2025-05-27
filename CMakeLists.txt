cmake_minimum_required(VERSION 3.31)
project(AlgoritmosOrdenacao C)

set(CMAKE_C_STANDARD 11)

include_directories(funcoes/insertion_sort)
include_directories(funcoes/merge_sort)

add_executable(AlgoritmosOrdenacao
        funcoes/insertion_sort/insertion_sort.c
        funcoes/insertion_sort/insertion_sort.h
        funcoes/merge_sort/merge_sort.c
        funcoes/merge_sort/merge_sort.h
        main.c)
