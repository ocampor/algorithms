cmake_minimum_required(VERSION 3.15)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_library(collectionslib SHARED collections/linked_list.cpp collections/linked_list.h collections/stack.cpp collections/stack.h collections/queue.cpp collections/queue.h)

add_executable(algorithms main.cpp)
add_executable(test tests/test_linked_list.cpp tests/test_stack.cpp tests/test_queue.cpp)

target_link_libraries(algorithms PRIVATE collectionslib)
