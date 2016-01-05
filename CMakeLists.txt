cmake_minimum_required(VERSION 3.3)
project(OrderBook)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

set(SOURCE_FILES main.cpp)
add_executable(OrderBook ${SOURCE_FILES})

include_directories(main)

add_subdirectory(main/src)
add_subdirectory(test)

target_link_libraries(OrderBook main)