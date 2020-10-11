cmake_minimum_required (VERSION 3.8)

project (01)

set(CMAKE_BUILD_TYPE Debug) 

include_directories("include/")

add_library(sharedLib SHARED
                                "src/base.cpp"
                                "src/Q01.cpp"
                                "src/Q02.cpp"
                                "src/Q03.cpp"
                                "src/Q04.cpp"
                                "src/Q05.cpp"
                                
                                "src/QBase.cc"
                                "src/Q43.cc"
                                "src/Q44.cc"
                                "src/Q45.cc"
                                )

add_executable(m main.cpp)
target_link_libraries(m sharedLib)

