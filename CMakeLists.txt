cmake_minimum_required(VERSION 3.5)
project(pagedArray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp paged_Array.cpp paged_Array.h Insertionsort.cpp Insertionsort.h Quicksort.cpp Quicksort.h fileGnerator.cpp fileGnerator.h slotManagr.cpp slotManagr.h Selectionsort.cpp Selectionsort.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(pagedArray ${SOURCE_FILES})