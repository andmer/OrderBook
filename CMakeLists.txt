cmake_minimum_required(VERSION 3.3)
project(OrderBook)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(BOOST_ROOT "C:/opt/boost_1_60_0")
set(Boost_INCLUDE_DIR "C:/opt/boost_1_60_0")
find_package(Boost 1.60.0)
if(Boost_FOUND)
    message(STATUS "It works!")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(SOURCE_FILES main.cpp)
add_executable(OrderBook ${SOURCE_FILES})

include_directories(main)

add_subdirectory(main/src)
add_subdirectory(test)

target_link_libraries(OrderBook main)