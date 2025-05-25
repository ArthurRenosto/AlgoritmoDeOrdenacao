cmake_minimum_required(VERSION 3.15)
project(AlgoritmoDeOrdenacao C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgoritmoDeOrdenacao main.c funcoes/insertion_sort/insertion_sort.c
        funcoes/insertion_sort/insertion_sort.h)