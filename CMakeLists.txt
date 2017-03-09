cmake_minimum_required(VERSION 3.5)
project(pagedArray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp paged_Array.cpp paged_Array.h Insertionsort.cpp Insertionsort.h ArrayConsolePrinter.cpp ArrayConsolePrinter.h Quicksort.cpp Quicksort.h fileGnerator.cpp fileGnerator.h slotManagr.cpp slotManagr.h)
add_executable(pagedArray ${SOURCE_FILES})