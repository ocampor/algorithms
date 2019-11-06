cmake_minimum_required(VERSION 3.15)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_library(expressionslib SHARED expressions/arithmetic.cpp expressions/arithmetic.h)
add_library(collectionslib SHARED collections/linked_list.cpp collections/linked_list.h collections/stack.cpp collections/stack.h collections/queue.cpp collections/queue.h)

add_executable(algorithms main.cpp)
add_executable(test_collections tests/test_linked_list.cpp tests/test_stack.cpp tests/test_queue.cpp)
add_executable(test_expressions tests/test_expressions.cpp)

target_link_libraries(algorithms PRIVATE collectionslib expressionslib)
target_link_libraries(test_collections PRIVATE collectionslib)
target_link_libraries(test_expressions PRIVATE expressionslib)
