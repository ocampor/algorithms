cmake_minimum_required(VERSION 3.15)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_library(CollectionsLib collections/linked_list.cpp collections/linked_list.h)

add_executable(algorithms main.cpp)

target_link_libraries(algorithms PRIVATE CollectionsLib)
