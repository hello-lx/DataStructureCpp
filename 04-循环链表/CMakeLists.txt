cmake_minimum_required (VERSION 3.8)

project (04)
SET(CMAKE_BUILD_TYPE "Debug") 

add_library(sharedLib SHARED
            DynamicArray.cpp)

add_executable(m main.cpp)
target_link_libraries(m sharedLib)
