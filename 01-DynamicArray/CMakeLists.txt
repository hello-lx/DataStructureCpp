cmake_minimum_required (VERSION 3.8)

project (01)

include_directories(".")

add_library(sharedLib SHARED
            DynamicArray.cpp)


add_executable(m main.cpp)
target_link_libraries(m sharedLib)