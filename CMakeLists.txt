cmake_minimum_required(VERSION 3.0.0)
project(TemplClasses VERSION 0.1.0)

add_executable(${CMAKE_PROJECT_NAME} deq.cpp)

include_directories()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 17)
#set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY "-E")
#add_compile_options()
