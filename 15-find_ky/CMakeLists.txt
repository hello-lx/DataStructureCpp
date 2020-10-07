cmake_minimum_required (VERSION 3.8)

project (01)
SET(CMAKE_BUILD_TYPE "Debug") 

include_directories("include/")

add_library(sharedLib SHARED
                                "src/Q01.cc"
                                "src/Q02.cc"
                                "src/Q03.cc"
                                "src/Q04.cc"
                                "src/Q05.cc")

add_executable(m main.cpp)
target_link_libraries(m sharedLib)